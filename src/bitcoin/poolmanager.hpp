#ifndef POOLMANAGER_HPP
#define POOLMANAGER_HPP

#include <bitcoin/escrowpool.hpp>

#include <cinttypes>
#include <memory>

#include <QObject>
#include <QList>
#include <QMap>

class PoolManager : QObject
{
public:
    PoolManager();

    void AddPool(EscrowPoolPtr pool);

    void RemovePool(EscrowPoolPtr poolToRemove);

    EscrowPoolPtr GetPoolByName(const std::string &);

    QList<EscrowPoolPtr> escrowPools;   // available pools

    std::string selectedPool;

private:
    QMap<std::string, EscrowPoolPtr> poolNameMap;
};

typedef std::shared_ptr<PoolManager> PoolManagerPtr;


#endif // POOLMANAGER_HPP
