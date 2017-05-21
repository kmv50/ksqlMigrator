#ifndef KSQLCONNECTOR_H
#define KSQLCONNECTOR_H

#include "ksqlconnector_global.h"
#include <sqlcredentials.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <iostream>
#include <QSqlRecord>
#include <QDebug>
#include <exception>

using namespace std;

typedef list<QVariant> DbRowValue;

typedef list<DbRowValue> DbTable;

typedef QVariantMap DbRowValueMap;

typedef QVariantList DbTableMap;


class KSQLCONNECTORSHARED_EXPORT KsqlConnector
{

public:
    KsqlConnector(SqlCredentials *credentias, const QString &ConectionName);
    ~KsqlConnector();
    void Exec(const QString &queryStr, const std::list<QVariant> Parameters);
    QSqlQueryModel * ReadModel(const QString &queryStr, const std::list<QVariant> Parameters);
    DbTableMap  ReadMap(const QString &queryStr, const std::list<QVariant> Parameters);
    inline QString GetLastError(){return LastError;}
private:
    void OpenConnection();
    void CloseConnection();
    QSqlDatabase *db;
    QString ConnectionName;
    QString User;
    QString Password;
    QString Host;
    QString DbName;
    QString LastError;
};

#endif // KSQLCONNECTOR_H
