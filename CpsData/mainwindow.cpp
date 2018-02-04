#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "logindialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->tableWidget);

    if (m_ApiAuthToken == "")
    {
        LoginDialog loginDialog(this);
        if (loginDialog.exec() == QDialog::Accepted)
        {
            QJsonObject authRequest = loginDialog.AuthRequest;

            m_ApiAuthToken = "Token";
        }
        else
        {
            QTimer::singleShot(0, this, SLOT(close()));
        }

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}
