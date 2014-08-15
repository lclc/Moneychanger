#ifndef SAMPLETYPEDEFS_HPP
#define SAMPLETYPEDEFS_HPP

#include <list>
#include <cinttypes>
#include <memory>

class SampleEscrowServer;
typedef std::shared_ptr<SampleEscrowServer> SampleEscrowServerPtr;

class SampleEscrowClient;
typedef std::shared_ptr<SampleEscrowClient> SampleEscrowClientPtr;

class SampleEscrowTransaction;
typedef std::shared_ptr<SampleEscrowTransaction> SampleEscrowTransactionPtr;
typedef std::list<SampleEscrowTransactionPtr> EscrowTransactionList;

class EscrowPool;
typedef std::shared_ptr<EscrowPool> EscrowPoolPtr;

#endif // SAMPLETYPEDEFS_HPP
