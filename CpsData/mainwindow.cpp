#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "logindialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    api(new ApiWebService(this))
{
    ui->setupUi(this);
    this->setCentralWidget(ui->tableWidget);

    QObject::connect(api, SIGNAL (InvalidAuthToken()), this, SLOT(RequestCredentials()));
    api->GetAuthToken();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete api;
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
