#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_buttonBox_accepted()
{
    /* From Angular Project
    let authRequest: TechCredential = new TechCredential({
            type: "local",
            value: {
              email: email,
              password: password
            }
        });
    */

    QJsonObject profile
    {
        qMakePair(QString("email"), QJsonValue(ui->lineEditEmail->text())),
        qMakePair(QString("password"), QJsonValue(ui->lineEditPwd->text()))
    };

    QJsonObject authRequest
    {
        qMakePair(QString("type"), QJsonValue("local")),
        qMakePair(QString("value"), QJsonValue(profile)),
        qMakePair(QString("ip"), QJsonValue("127.0.0.1"))
    };

    this->AuthRequest = authRequest;
}
