#pragma once

#include <QObject>
#include <QHostInfo>
#include <QHostAddress>

#include "techcredential.h"

class ApiWebService : public QObject
{
    Q_OBJECT
public:
    explicit ApiWebService(QObject *parent = nullptr);

    QString GetAuthToken();

signals:
    void InvalidAuthToken();

public slots:
    QString RequestAuthToken(const TechCredential credentials);

private slots:
    void ResolveApiRoot(const QHostInfo &host);

private:
    QString const API_ADDRESS = "dev.cps-data.com";
    QString const API_ROOT = "/api/";
    QHostAddress m_ApiRootAddress;

    QString m_AuthToken;
};
