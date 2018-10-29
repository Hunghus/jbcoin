//------------------------------------------------------------------------------
/*
    This file is part of jbcoind: https://github.com/jbcoin/jbcoind
    Copyright (c) 2012, 2013 JBCoin Labs Inc.

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

#ifndef JBCOIN_RPC_TESTOUTPUTSUITE_H_INCLUDED
#define JBCOIN_RPC_TESTOUTPUTSUITE_H_INCLUDED

#include <jbcoin/json/Output.h>
#include <jbcoin/json/Writer.h>
#include <test/jtx/TestSuite.h>

namespace jbcoin {
namespace test {

class TestOutputSuite : public TestSuite
{
protected:
    std::string output_;
    std::unique_ptr <Json::Writer> writer_;

    void setup (std::string const& testName)
    {
        testcase (testName);
        output_.clear ();
        writer_ = std::make_unique <Json::Writer> (
            Json::stringOutput (output_));
    }

    // Test the result and report values.
    void expectResult (std::string const& expected,
                       std::string const& message = "")
    {
        writer_.reset ();

        expectEquals (output_, expected, message);
    }
};

} // test
} // jbcoin

#endif
