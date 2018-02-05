#pragma once

#include <QHostInfo>
#include <QJsonObject>

class TechCredential
{
public:
    explicit TechCredential();
    TechCredential(const QString sEmail, const QString sPassword); // Simple Credentials
    ~TechCredential();

    QJsonObject GenerateAuthRequest();

signals:

public slots:

private:
    QString m_sType;
    QJsonObject m_jCredentials;
    QHostAddress m_LocalIp;
};
