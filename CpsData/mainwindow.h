#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "apiwebservice.h"
#include "techcredential.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void RequestCredentials();

private slots:
    void on_actionQuit_triggered();

private:
    Ui::MainWindow *ui;

    ApiWebService *api;
};

#endif // MAINWINDOW_H
