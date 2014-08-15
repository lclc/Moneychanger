#ifndef BTCWALLETPWDLG_H
#define BTCWALLETPWDLG_H

#include <QWidget>

namespace Ui {
class BtcWalletPwDlg;
}

class QMutex;
class BtcJson;

class BtcWalletPwDlg : public QWidget
{
    Q_OBJECT

public:
    explicit BtcWalletPwDlg(QWidget *parent = 0);
    ~BtcWalletPwDlg();

    std::string WaitForPassword();

    std::string password;

private slots:
    void on_buttonUnlock_clicked();

private:
    Ui::BtcWalletPwDlg *ui;

    std::shared_ptr<QMutex> mutex;
    std::shared_ptr<BtcJson> btcJson;
    bool waitingForInput;
};

typedef std::shared_ptr<BtcWalletPwDlg> BtcWalletPwDlgPtr;

#endif // BTCWALLETPWDLG_H
