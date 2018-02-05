#include "startup.h"
#include "mainwindow.h"
#include "utils.h"
#include "settings.h"
#include "provider.h"

namespace CpsData
{
    Startup::Startup() :
        QObject(nullptr),
        m_mainWindow(*new MainWindow(nullptr))
    {
        Settings& settings = Provider::GetSettingsAsSingleton();
        settings.ParseJsonData();
    }

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
