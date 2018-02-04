#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextStream>
#include <QFileDialog>
#include <QFile>
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

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "D://");
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::information(this, "Title", "File failed to open");
    }

    QTextStream outStream(&file);

    QString text = ui->textEdit->toPlainText();
    outStream << text;
    file.flush();
    file.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filter = "All Files (*.*) ;; Text Files (*.txt) ;; XML Files (*.xml)";
    QString fileName = QFileDialog::getOpenFileName(this, "Save File", "D://", filter);
    QFile file(fileName);

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "Title", "File failed to open");
    }

    QTextStream inStream(&file);

    QString text = inStream.readAll();
    ui->textEdit->setPlainText(text);
    file.close();
}
