#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDir dir("C:/Users");
    if (dir.exists())
    {
        QMessageBox::information(this, "Title", "True");
    }
    else
    {
        QMessageBox::information(this, "Title", "False");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
