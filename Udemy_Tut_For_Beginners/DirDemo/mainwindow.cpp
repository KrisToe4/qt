#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDir dir;
    foreach (QFileInfo info, dir.drives()) {
        ui->comboBox->addItem(info.absoluteFilePath());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
