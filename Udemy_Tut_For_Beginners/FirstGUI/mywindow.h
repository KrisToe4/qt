#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>

namespace Ui {
class MyWindow;
}

class MyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyWindow(QWidget *parent = 0);
    ~MyWindow();

private slots:
    void on_pushButtonClose_clicked();

private:
    Ui::MyWindow *ui;
};

#endif // MYWINDOW_H
