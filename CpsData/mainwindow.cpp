#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindialog.h"
#include "utils.h"

namespace CpsData
{
    MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        api(new ApiWebService(this))
    {
        ui->setupUi(this);
        this->setCentralWidget(ui->tblTechList);

        QObject::connect(api, SIGNAL (InvalidAuthToken()), this, SLOT(RequestCredentials()));
        api->GetAuthToken();
    }

    MainWindow::~MainWindow()
    {
        Utils::DestructorMsg(this);
        delete ui;
    }


    // Menu Options
    void MainWindow::on_actionQuit_triggered()
    {
        close();
    }

    void MainWindow::RequestCredentials()
    {
        LoginDialog loginDialog(this);
        QObject::connect(&loginDialog, SIGNAL(CredentialsValidated(TechCredential)), this->api, SLOT(RequestAuthToken(TechCredential)));

        if (loginDialog.exec() != QDialog::Accepted)
        {
            QTimer::singleShot(0, this, SLOT(close()));
        }
    }
}
