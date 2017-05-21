#ifndef ENGINEVALUES_H
#define ENGINEVALUES_H
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include <QQmlContext>
#include <control.h>

namespace Engine {

class EngineValues
{
public:
    EngineValues();
    QQmlContext *getContext();
    void RegisterContext(QQmlContext *value);
    QObject *getControls();
    void RegisterControls(QObject *value);
    Control * findControlbyName(const QString &value);
    void ShowMessageBox(const QString &title , const QString &msn);
    void loadQmlPage(const QString &qmlName);
private:
    QQmlContext *context;
    QObject *Controls;
};

}

#endif // ENGINEVALUES_H
