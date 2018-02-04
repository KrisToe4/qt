#include "techcredential.h"

TechCredential::TechCredential()
{
    this->m_sType = "";
    this->m_jCredentials = {};
}

TechCredential::TechCredential(QString const sEmail, QString const sPassword)
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
        qMakePair(QString("ip"), QJsonValue("127.0.0.1"))
    };

    return authRequest;
}
