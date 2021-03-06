//------------------------------------------------------------------------------
/*
    This file is part of jbcoind: https://github.com/jbcoin/jbcoind
    Copyright (c) 2016 JBCoin Labs Inc.

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

#ifndef JBCOIN_APP_MISC_VALIDATORSITE_H_INCLUDED
#define JBCOIN_APP_MISC_VALIDATORSITE_H_INCLUDED

#include <jbcoin/app/misc/ValidatorList.h>
#include <jbcoin/app/misc/detail/Work.h>
#include <jbcoin/basics/Log.h>
#include <jbcoin/basics/StringUtilities.h>
#include <jbcoin/json/json_value.h>
#include <boost/asio.hpp>
#include <mutex>
#include <memory>

namespace jbcoin {

/**
    Validator Sites
    ---------------

    This class manages the set of configured remote sites used to fetch the
    latest published recommended validator lists.

    Lists are fetched at a regular interval.
    Fetched lists are expected to be in JSON format and contain the following
    fields:

    @li @c "blob": Base64-encoded JSON string containing a @c "sequence", @c
        "expiration", and @c "validators" field. @c "expiration" contains the
        JBCoin timestamp (seconds since January 1st, 2000 (00:00 UTC)) for when
        the list expires. @c "validators" contains an array of objects with a
        @c "validation_public_key" and optional @c "manifest" field.
        @c "validation_public_key" should be the hex-encoded master public key.
        @c "manifest" should be the base64-encoded validator manifest.

    @li @c "manifest": Base64-encoded serialization of a manifest containing the
        publisher's master and signing public keys.

    @li @c "signature": Hex-encoded signature of the blob using the publisher's
        signing key.

    @li @c "version": 1

    @li @c "refreshInterval" (optional)
*/
class ValidatorSite
{
    friend class Work;

private:
    using error_code = boost::system::error_code;
    using clock_type = std::chrono::system_clock;

    struct Site
    {
        struct Status
        {
            clock_type::time_point refreshed;
            ListDisposition disposition;
            std::string message;
        };

        struct Resource
        {
            explicit Resource(std::string u);
            std::string uri;
            parsedURL pUrl;
        };
        using ResourcePtr = std::shared_ptr<Resource>;

        explicit Site(std::string uri);

        /// the original uri as loaded from config
        ResourcePtr loadedResource;

        /// the resource to to request at <timer>
        /// intervals. same as loadedResource
        /// except in the case of a permanent redir.
        ResourcePtr startingResource;

        /// the active resource being requested.
        /// same as startingResource except
        /// when we've gotten a temp redirect
        ResourcePtr activeResource;

        unsigned short redirCount;
        std::chrono::minutes refreshInterval;
        clock_type::time_point nextRefresh;
        boost::optional<Status> lastRefreshStatus;
    };

    boost::asio::io_service& ios_;
    ValidatorList& validators_;
    beast::Journal j_;
    std::mutex mutable sites_mutex_;
    std::mutex mutable state_mutex_;

    std::condition_variable cv_;
    std::weak_ptr<detail::Work> work_;
    boost::asio::basic_waitable_timer<clock_type> timer_;

    // A list is currently being fetched from a site
    std::atomic<bool> fetching_;

    // One or more lists are due to be fetched
    std::atomic<bool> pending_;
    std::atomic<bool> stopping_;

    // The configured list of URIs for fetching lists
    std::vector<Site> sites_;

public:
    ValidatorSite (
        boost::asio::io_service& ios,
        ValidatorList& validators,
        beast::Journal j);
    ~ValidatorSite ();

    /** Load configured site URIs.

        @param siteURIs List of URIs to fetch published validator lists

        @par Thread Safety

        May be called concurrently

        @return `false` if an entry is invalid or unparsable
    */
    bool
    load (
        std::vector<std::string> const& siteURIs);

    /** Start fetching lists from sites

        This does nothing if list fetching has already started

        @par Thread Safety

        May be called concurrently
    */
    void
    start ();

    /** Wait for current fetches from sites to complete

        @par Thread Safety

        May be called concurrently
    */
    void
    join ();

    /** Stop fetching lists from sites

        This blocks until list fetching has stopped

        @par Thread Safety

        May be called concurrently
    */
    void
    stop ();

    /** Return JSON representation of configured validator sites
     */
    Json::Value
    getJson() const;

private:
    /// Queue next site to be fetched
    void
    setTimer ();

    /// Fetch site whose time has come
    void
    onTimer (
        std::size_t siteIdx,
        error_code const& ec);

    /// Store latest list fetched from site
    void
    onSiteFetch (
        boost::system::error_code const& ec,
        detail::response_type&& res,
        std::size_t siteIdx);

    /// Initiate request to given resource.
    /// lock over sites_mutex_ required
    void
    makeRequest (
        Site::ResourcePtr resource,
        std::size_t siteIdx,
        std::lock_guard<std::mutex>& lock);

    /// Parse json response from validator list site.
    /// lock over sites_mutex_ required
    void
    parseJsonResponse (
        detail::response_type& res,
        std::size_t siteIdx,
        std::lock_guard<std::mutex>& lock);

    /// Interpret a redirect response.
    /// lock over sites_mutex_ required
    Site::ResourcePtr
    processRedirect (
        detail::response_type& res,
        std::size_t siteIdx,
        std::lock_guard<std::mutex>& lock);
};

} // jbcoin

#endif
