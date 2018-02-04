#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "logindialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (m_ApiAuthToken == "")
    {
        LoginDialog loginDialog(this);
        if (loginDialog.exec() == QDialog::Accepted)
        {
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
