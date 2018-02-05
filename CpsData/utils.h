#pragma once

class Utils
{
public:
    Utils();

    static void DestructorMsg(QString value);
    static void DestructorMsg(QObject *object);
};
