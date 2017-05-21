#ifndef BASECLASS_H
#define BASECLASS_H
#include <enginevalues.h>
#include <QObject>
#include <sqlcredentials.h>
#include <ksqlconnector.h>
extern Engine::EngineValues * Core;

class BaseClass: public QObject
{
   Q_OBJECT
protected:
    QString QMLpath;
    KsqlConnector *sql;
public:
    BaseClass(const QString &path) {
        QMLpath = path;
        sql = NULL;
    }

    virtual ~BaseClass(){}

    void BeforeLoad(){

    }

    virtual void onLoad() = 0;

    void Show(){
        BeforeLoad();
        try{
            Core->loadQmlPage(QMLpath);
        }catch(exception ex){
            Core->ShowMessageBox("Error al cargar qml",QString::fromLocal8Bit(ex.what()));
            return;
        }

        onLoad();
    }
};

#endif // BASECLASS_H
