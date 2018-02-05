#include <QApplication>

#include "startup.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CpsData::Startup startup;
    startup.show();

    return a.exec();
}
