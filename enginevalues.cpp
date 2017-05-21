#include "enginevalues.h"

Engine::EngineValues::EngineValues()
{

}

QQmlContext *Engine::EngineValues::getContext()
{
    return context;
}

void Engine::EngineValues::RegisterContext(QQmlContext *value)
{
    context = value;
}

QObject *Engine::EngineValues::getControls()
{
    return Controls;
}

void Engine::EngineValues::RegisterControls(QObject *value)
{
    Controls = value;
}

Engine::Control *Engine::EngineValues::findControlbyName(const QString &value)
{
    QObject *c = Controls->findChild<QObject *>(value);
    if(c == NULL || c == nullptr){
        throw runtime_error("Controlador no encontrado");
    }

    return new Control(c);

}

void Engine::EngineValues::ShowMessageBox(const QString &title, const QString &msn)
{    
    try{
        QMetaObject::invokeMethod(Controls,"showMessageBox",Q_ARG(QVariant,title),Q_ARG(QVariant,msn));
    }catch(exception &ex){
        qDebug() << ex.what();
    }
}

void Engine::EngineValues::loadQmlPage(const QString &qmlName)
{
    try{
        findControlbyName("MainLayout")->getRawControl()->setProperty("source",qmlName);
    }catch(exception ex){
        throw ex;
    }

}
