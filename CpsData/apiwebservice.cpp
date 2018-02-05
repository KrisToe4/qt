#include "apiwebservice.h"
#include "utils.h"

ApiWebService::ApiWebService(QObject *parent) : QObject(parent)
{
    QHostInfo::lookupHost(this->API_ADDRESS, this, SLOT(ResolveApiRoot(QHostInfo)));
}

ApiWebService::~ApiWebService()
{
    Utils::DestructorMsg(this);
}

QString ApiWebService::GetAuthToken()
{
    if (m_AuthToken == "")
    {
        emit InvalidAuthToken();
    }

    return m_AuthToken;
}

QString ApiWebService::RequestAuthToken(const TechCredential credentials)
{
    m_AuthToken = "token";

    return m_AuthToken;
}

void ApiWebService::ResolveApiRoot(const QHostInfo &host)
{
    // From http://doc.qt.io/qt-5/qhostinfo.html#lookupHost
    if (host.error() != QHostInfo::NoError)
    {
        qDebug() << QObject::tr("Lookup failed:") << host.errorString();
        this->m_ApiRootAddress = QHostAddress::LocalHost;
        return;
    }

    const auto addresses = host.addresses();
    if (addresses.length() > 0)
    {
        qDebug() << QObject::tr("Found address:") << addresses[0].toString();
        this->m_ApiRootAddress = addresses[0];
    }

}
