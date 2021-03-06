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


// This has to be included early to prevent an obscure MSVC compile error
#include <boost/asio/deadline_timer.hpp>

#include <jbcoin/protocol/JsonFields.h>
#include <jbcoin/rpc/RPCHandler.h>
#include <jbcoin/rpc/handlers/Handlers.h>

#include <jbcoin/rpc/handlers/PathFind.cpp>
#include <jbcoin/rpc/handlers/PayChanClaim.cpp>
#include <jbcoin/rpc/handlers/Peers.cpp>
#include <jbcoin/rpc/handlers/Ping.cpp>
#include <jbcoin/rpc/handlers/Print.cpp>
#include <jbcoin/rpc/handlers/Random.cpp>
#include <jbcoin/rpc/handlers/JBCoinPathFind.cpp>
#include <jbcoin/rpc/handlers/ServerInfo.cpp>
#include <jbcoin/rpc/handlers/ServerState.cpp>
#include <jbcoin/rpc/handlers/SignFor.cpp>
#include <jbcoin/rpc/handlers/SignHandler.cpp>
#include <jbcoin/rpc/handlers/Stop.cpp>
#include <jbcoin/rpc/handlers/Submit.cpp>
#include <jbcoin/rpc/handlers/SubmitMultiSigned.cpp>
#include <jbcoin/rpc/handlers/Subscribe.cpp>
#include <jbcoin/rpc/handlers/TransactionEntry.cpp>
#include <jbcoin/rpc/handlers/Tx.cpp>
#include <jbcoin/rpc/handlers/TxHistory.cpp>
#include <jbcoin/rpc/handlers/UnlList.cpp>
#include <jbcoin/rpc/handlers/Unsubscribe.cpp>
#include <jbcoin/rpc/handlers/ValidationCreate.cpp>
#include <jbcoin/rpc/handlers/ValidationSeed.cpp>
#include <jbcoin/rpc/handlers/Validators.cpp>
#include <jbcoin/rpc/handlers/ValidatorListSites.cpp>
#include <jbcoin/rpc/handlers/WalletPropose.cpp>

#include <jbcoin/rpc/impl/Handler.cpp>
#include <jbcoin/rpc/impl/LegacyPathFind.cpp>
#include <jbcoin/rpc/impl/Role.cpp>
#include <jbcoin/rpc/impl/RPCHandler.cpp>
#include <jbcoin/rpc/impl/RPCHelpers.cpp>
#include <jbcoin/rpc/impl/ServerHandlerImp.cpp>
#include <jbcoin/rpc/impl/ShardArchiveHandler.cpp>
#include <jbcoin/rpc/impl/Status.cpp>
#include <jbcoin/rpc/impl/TransactionSign.cpp>


