#pragma once
#include <memory>

namespace CpsData
{
    class Settings;

    class Provider final
    {
    public:
        Provider();
        static Settings& GetSettingsAsSingleton();

    private:
        static std::unique_ptr<Settings> m_settings;


        explicit Provider(const Provider& rhs) = delete;
        Provider& operator= (const Provider& rhs) = delete;
    };
}



