# The JBC Ledger

The JBC Ledger is a decentralized cryptographic ledger powered by a network of peer-to-peer servers. The JBC Ledger uses a novel Byzantine Fault Tolerant consensus algorithm to settle and record transactions in a secure distributed database without a central operator.

## JBC
JBC is a public, counterparty-less asset native to the JBC Ledger, and is designed to bridge the many different currencies in use worldwide. JBC is traded on the open-market and is available for anyone to access. The JBC Ledger was created in 2012 with a finite supply of 100 billion units of JBC. Its creators gifted 80 billion JBC to a company, now called [JBCoin](https://jbcoin.com/), to develop the JBC Ledger and its ecosystem.  JBCoin uses JBC the help build the Internet of Value, ushering in a world in which money moves as fast and efficiently as information does today.

## `jbcoind`
The server software that powers the JBC Ledger is called `jbcoind` and is available in this repository under the permissive [ISC open-source license](LICENSE). The `jbcoind` server is written primarily in C++ and runs on a variety of platforms.


# Key Features of the JBC Ledger

- **[Censorship-Resistant Transaction Processing][]:** No single party decides which transactions succeed or fail, and no one can "roll back" a transaction after it completes. As long as those who choose to participate in the network keep it healthy, they can settle transactions in seconds.
- **[Fast, Efficient Consensus Algorithm][]:** The JBC Ledger's consensus algorithm settles transactions in 4 to 5 seconds, processing at a throughput of up to 1500 transactions per second. These properties put JBC at least an order of magnitude ahead of other top digital assets.
- **[Finite JBC Supply][]:** When the JBC Ledger began, 100 billion JBC were created, and no more JBC will ever be created. (Each JBC is subdivisible down to 6 decimal places, for a grand total of 100 quintillion _drops_ of JBC.) The available supply of JBC decreases slowly over time as small amounts are destroyed to pay transaction costs.
- **[Responsible Software Governance][]:** A team of full-time, world-class developers at JBCoin maintain and continually improve the JBC Ledger's underlying software with contributions from the open-source community. JBCoin acts as a steward for the technology and an advocate for its interests, and builds constructive relationships with governments and financial institutions worldwide.
- **[Secure, Adaptable Cryptography][]:** The JBC Ledger relies on industry standard digital signature systems like ECDSA (the same scheme used by Bitcoin) but also supports modern, efficient algorithms like Ed25519. The extensible nature of the JBC Ledger's software makes it possible to add and disable algorithms as the state of the art in cryptography advances.
- **[Modern Features for Smart Contracts][]:** Features like Escrow, Checks, and Payment Channels support cutting-edge financial applications including the [Interledger Protocol](https://interledger.org/). This toolbox of advanced features comes with safety features like a process for amending the network and separate checks against invariant constraints.
- **[On-Ledger Decentralized Exchange][]:** In addition to all the features that make JBC useful on its own, the JBC Ledger also has a fully-functional accounting system for tracking and trading obligations denominated in any way users want, and an exchange built into the protocol. The JBC Ledger can settle long, cross-currency payment paths and exchanges of multiple currencies in atomic transactions, bridging gaps of trust with JBC.

[Censorship-Resistant Transaction Processing]: https://developers.jbcoin.com/jbc-ledger-overview.html#censorship-resistant-transaction-processing
[Fast, Efficient Consensus Algorithm]: https://developers.jbcoin.com/jbc-ledger-overview.html#fast-efficient-consensus-algorithm
[Finite JBC Supply]: https://developers.jbcoin.com/jbc-ledger-overview.html#finite-jbc-supply
[Responsible Software Governance]: https://developers.jbcoin.com/jbc-ledger-overview.html#responsible-software-governance
[Secure, Adaptable Cryptography]: https://developers.jbcoin.com/jbc-ledger-overview.html#secure-adaptable-cryptography
[Modern Features for Smart Contracts]: https://developers.jbcoin.com/jbc-ledger-overview.html#modern-features-for-smart-contracts
[On-Ledger Decentralized Exchange]: https://developers.jbcoin.com/jbc-ledger-overview.html#on-ledger-decentralized-exchange


## Source Code
[![travis-ci.org: Build Status](https://travis-ci.org/jbcoin/jbcoind.png?branch=develop)](https://travis-ci.org/jbcoin/jbcoind)
[![codecov.io: Code Coverage](https://codecov.io/gh/jbcoin/jbcoind/branch/develop/graph/badge.svg)](https://codecov.io/gh/jbcoin/jbcoind)

### Repository Contents

| Folder     | Contents                                         |
|:-----------|:-------------------------------------------------|
| `./bin`    | Scripts and data files for JBCoin integrators.   |
| `./Builds` | Platform-specific guides for building `jbcoind`. |
| `./docs`   | Source documentation files and doxygen config.   |
| `./cfg`    | Example configuration files.                     |
| `./src`    | Source code.                                     |

Some of the directories under `src` are external repositories included using
git-subtree. See those directories' README files for more details.


## See Also

* [JBC Ledger Dev Portal](https://developers.jbcoin.com/)
* [JBC News](https://jbcoin.com/category/jbc/)
* [Setup and Installation](https://developers.jbcoin.com/install-jbcoind.html)

To learn about how JBCoin is transforming global payments, visit
<https://jbcoin.com/contact/>.
