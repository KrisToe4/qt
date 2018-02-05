#include <QString>
#include <QDebug>

#include "utils.h"

static QString DESTRUCTOR_MSG = QStringLiteral("Running the %1 destructor.");

void Utils::DestructorMsg(QString value)
{
    qDebug() << DESTRUCTOR_MSG.arg(value);
}

void Utils::DestructorMsg(QObject* object)
{
    DestructorMsg(object->metaObject()->className());
}
