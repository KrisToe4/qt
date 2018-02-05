#pragma once

#include <QObject>

class MainWindow;

class Startup : public QObject
{
    Q_OBJECT
public:
    explicit Startup();
    ~Startup();

    void show();
private:
    MainWindow& m_mainWindow;
};
