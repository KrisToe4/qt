#include "apiwebservice.h"

ApiWebService::ApiWebService(QObject *parent) : QObject(parent)
{
    QHostInfo::lookupHost(this->API_ROOT, this, SLOT(resolveApiRoot(QHostInfo)));

    if (m_AuthToken == "")
    {
        emit InvalidAuthToken();
    }
}

QString ApiWebService::RequestAuthToken(TechCredential credentials)
{
    m_AuthToken = "token";

    return m_AuthToken;
}

void ApiWebService::ResolveApiRoot(const QHostInfo &host)
{
    // From http://doc.qt.io/qt-5/qhostinfo.html#lookupHost
    if (host.error() != QHostInfo::NoError)
    {
        qDebug() << "Lookup failed:" << host.errorString();
        return;
    }

    const auto addresses = host.addresses();
    if (addresses.length() > 0)
    {
        qDebug() << "Found address:" << addresses[0].toString();
        this->m_ApiRootAddress = addresses[0];
    }

}