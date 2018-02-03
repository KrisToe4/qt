#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->checkBox->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->checkBox->isChecked())
    {
        QMessageBox::information(this, "Result", "User Likes Apples.");
    }
    else {
        QMessageBox::information(this, "Result", "User doesn't like Apples.");
    }
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (arg1)
    {
        QMessageBox::information(this, "Result", "User Likes Apples.");
    }
    else {
        QMessageBox::information(this, "Result", "User doesn't like Apples.");
    }
}
