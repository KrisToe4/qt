#include <QApplication>

#include "startup.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Startup startup;
    startup.show();

    return a.exec();
}
