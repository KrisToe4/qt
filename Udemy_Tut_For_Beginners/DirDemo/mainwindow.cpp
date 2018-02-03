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

    QDir dir2("D:/Work/Surge/qt/Udemy_Tut_For_Beginners/DirDemo");
    foreach (QFileInfo info, dir2.entryInfoList()) {

        if (info.isDir())
        {
            ui->listWidget->addItem("Dir: " + info.absoluteFilePath());
        }

        if (info.isFile())
        {
            ui->listWidget->addItem("File: " + info.absoluteFilePath());
        }

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
        QDir dir("D:/Work/Surge/qt/Udemy_Tut_For_Beginners/DirDemo/Test");
        if (!dir.exists())
        {
            dir.mkpath("D:/Work/Surge/qt/Udemy_Tut_For_Beginners/DirDemo/Test");
        }
        else
        {
            QMessageBox::information(this, "Title", "Dir Exists");
        }
}
