#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->addItem(QIcon(":/resource/img/green-light.png"), "Mark");
    ui->comboBox->addItem(QIcon(":/resource/img/red-light.png"), "John");
    ui->comboBox->addItem("Ralph");
}

MainWindow::~MainWindow()
{
    delete ui;
}
