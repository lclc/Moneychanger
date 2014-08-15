#ifndef ESCROWPOOL_HPP
#define ESCROWPOOL_HPP

#include <cinttypes>
#include <memory>

#include <QList>
#include <QString>
#include <map>

class SampleEscrowServer;
class QThread;

typedef std::shared_ptr<SampleEscrowServer> SampleEscrowServerPtr;

class EscrowPool
{
public:
    EscrowPool(uint32_t sigsRequired);

    // add server to pool
    void AddEscrowServer(SampleEscrowServerPtr server);

    void RemoveEscrowServer(SampleEscrowServerPtr server);

    QList<SampleEscrowServerPtr> escrowServers;     // servers that are part of this pool

    std::string poolName;

    std::map<std::string, SampleEscrowServerPtr> serverNameMap;
    std::map<std::string, QThread*> serverThreadMap;

    uint32_t sigsRequired;

    bool containsHostedServer;

private:

};

typedef std::shared_ptr<EscrowPool> EscrowPoolPtr;

#endif // ESCROWPOOL_HPP
