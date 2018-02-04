#ifndef TECHCREDENTIAL_H
#define TECHCREDENTIAL_H

#include <QObject>
#include <QJsonObject>

class TechCredential
{
public:
    explicit TechCredential();
    TechCredential(const QString sEmail, const QString sPassword); // Simple Credentials

    QJsonObject GenerateAuthRequest();


signals:

public slots:

private:
    QString m_sType;
    QJsonObject m_jCredentials;
};

#endif // TECHCREDENTIAL_H
