#include "logindialog.h"
#include "ui_logindialog.h"
#include "utils.h"

namespace CpsData
{
    LoginDialog::LoginDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::LoginDialog)
    {
        ui->setupUi(this);
    }

    LoginDialog::~LoginDialog()
    {
        Utils::DestructorMsg(this);
        delete ui;
    }

    void LoginDialog::on_buttonBox_accepted()
    {
        TechCredential credentials(ui->lineEditEmail->text(), ui->lineEditPwd->text());
        emit CredentialsValidated(credentials);
    }
}
