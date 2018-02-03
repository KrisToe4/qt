#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
    ui->comboBox->addItem(QIcon(":/resource/img/green-light.png"), "Mark");
    ui->comboBox->addItem(QIcon(":/resource/img/red-light.png"), "John");
    ui->comboBox->addItem("Ralph");
    */

    for (int i = 0; i < 10; i++)
    {
        ui->comboBox->addItem(QIcon(":/resource/img/green-light.png"), QString::number(i) + "name");
    }

    ui->comboBox->insertItem(3, QIcon(":/resource/img/green-light.png"), "New Text");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this, "Title", ui->comboBox->currentText());
}
