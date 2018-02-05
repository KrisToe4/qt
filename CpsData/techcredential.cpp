#include "techcredential.h"
#include "utils.h"

TechCredential::TechCredential()
{
    this->m_sType = "";
    this->m_jCredentials = {};
    this->m_LocalIp = QHostAddress::LocalHost;
}

TechCredential::~TechCredential()
{
    Utils::DestructorMsg("Tech Credentials Destructor.");
}

TechCredential::TechCredential(QString const sEmail, QString const sPassword) : TechCredential()
{
    this->m_sType = "local";
    this->m_jCredentials =
    {
        qMakePair(QString("email"), QJsonValue(sEmail)),
        qMakePair(QString("password"), QJsonValue(sPassword))
    };
}

QJsonObject TechCredential::GenerateAuthRequest()
{
    /* From Angular Project
    let authRequest: TechCredential = new TechCredential({
            type: "local",
            value: {
              email: email,
              password: password
            }
        });
    */

    QJsonObject authRequest
    {
        qMakePair(QString("type"), QJsonValue("local")),
        qMakePair(QString("value"), QJsonValue(this->m_jCredentials)),
        qMakePair(QString("ip"), QJsonValue(this->m_LocalIp.toString()))
    };

    return authRequest;
}
