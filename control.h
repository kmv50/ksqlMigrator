#ifndef CONTROL_H
#define CONTROL_H

#include <QObject>
#include <stdexcept>
#include <QDebug>
using namespace std;

namespace Engine {

class Control
{
public:
    Control(QObject *widget);
    QString GetText();
    QString GetText(const QString &Error);
    void SetText(const QString &text);
    QObject *getRawControl();

private:
    QObject *widget;
};

}
#endif // CONTROL_H
