#pragma once
#include <QObject>

class QString;
class QStringListModel;
class QJsonParseError;
class QJsonObject;
class QFile;
class QDir;


namespace CpsData
{
    typedef std::pair<QJsonObject, QJsonParseError> JsonObjErrPair;

    class Settings : public QObject
    {
        Q_OBJECT
    public:
        explicit Settings(QObject *parent, QString fileName);
        void ParseJsonData();
        QString getAuthToken() const {return m_authToken;}

    signals:
        void NotifyStatusMessage(QString message);

    private:
        QString m_fileName;
        QString m_authToken;

        QString ReadJsonFile();
        QString ReadJsonFromInternalResource();
        void SendErrorMessage(const QString& msg);
        JsonObjErrPair GetJsonPair(const QString &rawJson);
        JsonObjErrPair GetJsonObject(const QString &rawJson);
        void ShowJsonParseError(QJsonParseError jsonError);
        QDir OpenConfigDirectory();
        void WriteDefaultsToStdConfigFile(QFile &stdConfigFile, const QString &settings);

        explicit Settings(const Settings& rhs) = delete;
        Settings& operator= (const Settings& rhs) = delete;
    };
}



