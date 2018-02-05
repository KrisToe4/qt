#include "settings.h"
#include <QString>
#include <QDir>
#include <QFile>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include <QJsonArray>
#include <QStringListModel>
#include <QStandardPaths>
#include <utility>
#include <QDebug>


namespace CpsData
{
    static auto RESOURCE_PREFIX =  QStringLiteral(":/json");

    Settings::Settings(QObject *parent, QString fileName) :
        QObject(parent),
        m_fileName(fileName),
        m_authToken ("")
    {
    }

    void Settings::ParseJsonData()
    {
        QString rawJson = ReadJsonFile();
        if (rawJson.size() == 0) return;

        auto jsonResult = GetJsonObject(rawJson);
        auto jsonError = jsonResult.second;
        if (jsonError.error != QJsonParseError::NoError)
        {
            ShowJsonParseError(jsonError);
        }
        auto jsonObject = jsonResult.first;
        m_authToken = jsonObject["authToken"].toString();
    }

    QString Settings::ReadJsonFile()
    {
        auto dftSettings = ReadJsonFromInternalResource();
        QDir configDir = OpenConfigDirectory();
        auto filePath = configDir.filePath(m_fileName);
        QFile settingsFile(filePath);
        if (settingsFile.exists())
        {
            if (!settingsFile.open(QFile::ReadOnly|QFile::Text))
            {
                SendErrorMessage("Could not open " + filePath);
                return dftSettings;
            }
            QString settings = settingsFile.readAll();
            settingsFile.close();
            return settings;
        }
        else
        {
            WriteDefaultsToStdConfigFile(settingsFile,dftSettings);
            return dftSettings;
        }
    }

    void Settings::WriteDefaultsToStdConfigFile(QFile& stdConfigFile,
                                                const QString &settings)
    {
        int length = settings.length();
        if (!stdConfigFile.open(QFile::WriteOnly|QFile::Text))
        {
            SendErrorMessage("Could not open file to write - "+ stdConfigFile.fileName());
        }

        auto bytesWritten = stdConfigFile.write(qPrintable(settings),length);
        if (bytesWritten != length)
        {
            SendErrorMessage("Could not write the settings to -"+ stdConfigFile.fileName());
            if (!stdConfigFile.remove())
            {
                SendErrorMessage("Couldn't remove configuration file. Please delete manually"+
                                 stdConfigFile.fileName());
            }
        }
        stdConfigFile.close();

    }

    QDir Settings::OpenConfigDirectory()
    {
        QDir configDir(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation));
        if (!configDir.exists())
        {
            QDir dir;
            dir.mkpath(configDir.path());
        }
        return configDir;
    }

    JsonObjErrPair Settings::GetJsonObject(const QString& rawJson)
    {
        QJsonParseError jsonParseError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(rawJson.toUtf8(),
                                                        &jsonParseError);
        QJsonObject jsonObject = jsonDoc.object();
        return std::make_pair(jsonObject, jsonParseError);
    }


    QString Settings::ReadJsonFromInternalResource()
    {
        QDir resourceDir (RESOURCE_PREFIX);
        if (!resourceDir.exists())
        {
            SendErrorMessage("Internal resource path missing "+
                             resourceDir.canonicalPath());
            return "";
        }
        auto path = resourceDir.filePath(m_fileName);
        QFile resourceFile(path);
        if (!resourceFile.open(QFile::ReadOnly| QFile::Text))
        {
            SendErrorMessage("Could not open internal resource " + path);
            return "";
        }
        QString settings = resourceFile.readAll();
        return settings;

    }

    void Settings::SendErrorMessage(const QString& msg)
    {
        emit NotifyStatusMessage(msg);
    }

    void Settings::ShowJsonParseError(QJsonParseError jsonError)
    {
        QString msg = tr("Error parsing Json settings file.\n");
        msg.append(jsonError.errorString());
        QMessageBox::critical(0,tr("CPS-Data"),msg);
    }
}
