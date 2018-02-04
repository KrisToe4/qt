#ifndef TECHCREDENTIAL_H
#define TECHCREDENTIAL_H

#include <QHostInfo>
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
    QHostAddress m_LocalIp;
};

#endif // TECHCREDENTIAL_H
