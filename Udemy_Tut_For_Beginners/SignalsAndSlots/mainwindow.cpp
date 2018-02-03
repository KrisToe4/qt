#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Programmatically create an event signal/slot connection
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            ui->progressBar, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //void              about
    //void              aboutQt
    //StandardButton    critical
    //StandardButton    information
    //StandardButton    question
    //StardardButton    warning
    QMessageBox::aboutQt(this, "My Message Box");
}
