#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix("D:/Work/Angular/cps-data/trunk/client/src/assets/logo.png");
    int width = ui->labelPicture->width();
    int height = ui->labelPicture->height();
    ui->labelPicture->setPixmap(pix.scaled(width,height,Qt::KeepAspectRatio));
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
        dialog = new Dialog(this);
        dialog->show();
    }
    else
    {
        QMessageBox::warning(this, "Login", "Username or password are not correct");
    }
}
