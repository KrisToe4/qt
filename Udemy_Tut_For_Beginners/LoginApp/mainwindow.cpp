#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonLogin_clicked()
{
    QString username = ui->lineEditUser->text();
    QString password = ui->lineEditPass->text();

    if ((username == "test") && (password == "test"))
    {
        QMessageBox::information(this, "Login", "Username and password are correct");
    }
    else
    {
        QMessageBox::warning(this, "Login", "Username or password are not correct");
    }
}
