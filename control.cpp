#include "control.h"


Engine::Control::Control(QObject *widget)
{
    this->widget = widget;
}

QString Engine::Control::GetText()
{
    return widget->property("text").toString();
}

QString Engine::Control::GetText(const QString &Error)
{
    QString str = GetText();
    if(str == NULL || str.trimmed().isEmpty())
        throw runtime_error(Error.toStdString().c_str());
    return str;
}

void Engine::Control::SetText(const QString &text)
{

}

QObject *Engine::Control::getRawControl()
{
    return widget;
}

