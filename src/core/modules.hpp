#ifndef MODULES_HPP
#define MODULES_HPP

#include <QScopedPointer>
#include <QPointer>

// This class will hold pointers to various modules so they can access eachother.
// Hierarchic layout would be possible too: BtcInterface -> BtcJson -> BtcRpc
class SampleEscrowManager;
class PoolManager; // has a list of all available pools
class TransactionManager; // has a list of pending and finished transactions
class BtcConnectDlg;
class SampleEscrowClient;
class BtcWalletPwDlg;

class BtcModules;


class Modules
{
public:
    Modules();
    ~Modules();

    static std::shared_ptr<SampleEscrowManager> sampleEscrowManager;
    static std::shared_ptr<PoolManager> poolManager;
    static std::shared_ptr<TransactionManager> transactionManager;
    static  QPointer<BtcConnectDlg> connectionManager;
    static std::shared_ptr<BtcWalletPwDlg> walletPwDlg;
    static std::shared_ptr<SampleEscrowClient> sampleEscrowClient;
    static std::shared_ptr<BtcModules> btcModules;

    static bool shutDown;

};

#endif // MODULES_HPP
