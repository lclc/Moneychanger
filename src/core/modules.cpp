#ifndef __STABLE_HPP__
#include <core/stable.hpp>
#endif

#include <core/modules.hpp>

#include <bitcoin/sampleescrowmanager.hpp>
#include <bitcoin/poolmanager.hpp>
#include <bitcoin/transactionmanager.hpp>
#include <bitcoin/sampleescrowclient.hpp>
#include <bitcoin-api/btcmodules.hpp>
#include <gui/widgets/btcconnectdlg.hpp>
#include <gui/widgets/btcwalletpwdlg.hpp>


std::shared_ptr<SampleEscrowManager> Modules::sampleEscrowManager;
std::shared_ptr<PoolManager> Modules::poolManager;
std::shared_ptr<TransactionManager> Modules::transactionManager;
QPointer<BtcConnectDlg> Modules::connectionManager;
std::shared_ptr<SampleEscrowClient> Modules::sampleEscrowClient;
std::shared_ptr<BtcModules> Modules::btcModules;
BtcWalletPwDlgPtr Modules::walletPwDlg;

bool Modules::shutDown;


Modules::Modules()
{
    sampleEscrowManager.reset(new SampleEscrowManager());
    poolManager.reset(new PoolManager());
    transactionManager.reset(new TransactionManager());
    connectionManager = new BtcConnectDlg();
    walletPwDlg.reset(new BtcWalletPwDlg());
    btcModules.reset(new BtcModules());
    sampleEscrowClient.reset(new SampleEscrowClient(btcModules));

    shutDown = false;

    btcModules->btcJson->SetPasswordCallback(fastdelegate::MakeDelegate(walletPwDlg.get(), &BtcWalletPwDlg::WaitForPassword));
}

Modules::~Modules()
{

}
