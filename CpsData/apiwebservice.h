#ifndef APIWEBSERVICE_H
#define APIWEBSERVICE_H

#include <QObject>
#include <QHostInfo>
#include <QHostAddress>

#include "techcredential.h"

class ApiWebService : public QObject
{
    Q_OBJECT
public:
    explicit ApiWebService(QObject *parent = nullptr);

signals:
    void InvalidAuthToken();

public slots:
    QString RequestAuthToken(TechCredential credentials);

private slots:
    void ResolveApiRoot(const QHostInfo &host);

private:
    QString const API_ROOT = "http://localhost:3000/api/";
    QHostAddress m_ApiRootAddress;

    QString m_AuthToken;
};

#endif // APIWEBSERVICE_H
