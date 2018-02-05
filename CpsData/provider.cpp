#include <QString>

#include "provider.h"
#include "settings.h"
#include "utils.h"

namespace CpsData
{
    static QString SETTINGS_FILE = QStringLiteral("settings.json");
    std::unique_ptr<Settings> Provider::m_settings = nullptr;

    Settings& Provider::GetSettingsAsSingleton()
    {
        if (m_settings == nullptr)
        {
            m_settings = Utils::make_unique<Settings>(nullptr,SETTINGS_FILE);
        }
        return *m_settings;
    }
}
