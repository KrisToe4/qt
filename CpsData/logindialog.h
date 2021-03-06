#pragma once

#include <QDialog>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonDocument>

#include "techcredential.h"

namespace Ui
{
    class LoginDialog;
}

namespace CpsData
{
    class LoginDialog : public QDialog
    {
        Q_OBJECT

    public:
        explicit LoginDialog(QWidget *parent = 0);
        ~LoginDialog();

        QJsonObject AuthRequest;

    signals:
        void CredentialsValidated(TechCredential credentials);

    private slots:
        void on_buttonBox_accepted();

    private:
        Ui::LoginDialog *ui;
    };
}
