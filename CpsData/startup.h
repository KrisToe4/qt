#ifndef STARTUP_H
#define STARTUP_H

#include <QObject>

class MainWindow;

class Startup : public QObject
{
    Q_OBJECT
public:
    explicit Startup();

    void show();
private:
    MainWindow& m_mainWindow;
};

#endif // STARTUP_H
