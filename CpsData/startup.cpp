#include "startup.h"
#include "mainwindow.h"
#include "utils.h"

namespace CpsData
{
    Startup::Startup() :
        QObject(nullptr),
        m_mainWindow(*new MainWindow(nullptr))
    {}

    Startup::~Startup()
    {
        Utils::DestructorMsg(this);
        delete &m_mainWindow;
    }

    void Startup::show()
    {
        m_mainWindow.show();
    }
}
