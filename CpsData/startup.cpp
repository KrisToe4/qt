#include "startup.h"
#include "mainwindow.h";

Startup::Startup() :
    QObject(nullptr),
    m_mainWindow(*new MainWindow(nullptr))
{

}

void Startup::show()
{
    m_mainWindow.show();
}
