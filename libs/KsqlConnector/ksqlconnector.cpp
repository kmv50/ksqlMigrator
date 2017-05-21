#include "ksqlconnector.h"


KsqlConnector::KsqlConnector(SqlCredentials *credentias , const QString &ConectionName = "DataSource1")
{
    Host = credentias->getServidor();
    User = credentias->getUsuario();
    Password = credentias->getPassword();
    DbName = credentias->getDBName();
    ConnectionName = ConectionName;
}

KsqlConnector::~KsqlConnector(){
    CloseConnection();
}

void KsqlConnector::OpenConnection(){

    db = new QSqlDatabase(QSqlDatabase::addDatabase("QMYSQL",ConnectionName));
    db->setHostName(Host);
    db->setUserName(User);
    db->setPassword(Password);
    if(DbName != NULL && DbName != "")
        db->setDatabaseName(DbName);

    if(!db->open()){
        throw std::runtime_error(db->lastError().text().toStdString());
    }
}


void KsqlConnector::CloseConnection(){
    if(db != nullptr && db != NULL){
        db->close();
        delete db;
        db = nullptr;
    }
}


void KsqlConnector::Exec(const QString &queryStr,const std::list<QVariant> Parameters){
    QSqlQuery *query = nullptr;
    bool StatusQuery = true;
    try{
        OpenConnection();
        query = new QSqlQuery(*db);

        if(Parameters.size() > 0){
            if(query->prepare(queryStr)){
                    for(auto parameter : Parameters)
                        query->addBindValue(parameter);
            }else{
                throw std::runtime_error(query->lastError().text().toStdString());
            }
            StatusQuery = query->exec();
        }else{
            StatusQuery = query->exec(queryStr);
        }

        if(!StatusQuery)
            throw std::runtime_error(query->lastError().text().toStdString());

        query->finish();
        delete query;
        CloseConnection();
    }catch(std::exception &e){
        delete query;
        cout << e.what() << endl;
        CloseConnection();
        throw;
    }
}



QSqlQueryModel * KsqlConnector::ReadModel(const QString &queryStr, const std::list<QVariant> Parameters){
    QSqlQuery *query = nullptr;
    QSqlQueryModel *model = new QSqlQueryModel;
    try{
        OpenConnection();
        query = new QSqlQuery(*db);

        if(query->prepare(queryStr)){
        for(auto parameter : Parameters)
            query->addBindValue(parameter);
        }else{
            throw std::runtime_error(query->lastError().text().toStdString());
        }

        model->setQuery(*query);
        query->finish();

        delete query;
        CloseConnection();
    }catch(std::exception &e){
        if(query != nullptr)
            delete query;

        cout << e.what() << endl;
        CloseConnection();
        throw;
    }
    return model;
}


DbTableMap KsqlConnector::ReadMap(const QString &queryStr, const std::list<QVariant> Parameters){
    QSqlQuery *query = nullptr;
    DbTableMap table;
    bool StatusQuery = true;
    try{
        OpenConnection();
        query = new QSqlQuery(*db);


        if(Parameters.size() > 0){
            if(query->prepare(queryStr)){
                    for(auto parameter : Parameters)
                        query->addBindValue(parameter);
            }else{
                throw std::runtime_error(query->lastError().text().toStdString());
            }
            StatusQuery = query->exec();
        }else{
            StatusQuery = query->exec(queryStr);
        }

        if(!StatusQuery)
            throw std::runtime_error(query->lastError().text().toStdString());

        QSqlRecord record = query->record();
        while(query->next()){
            DbRowValueMap Row;
            for(int i = 0 ; i < record.count() ; i++)
                Row[record.fieldName(i)] = query->value(i);

            table.push_back(Row);
        }

        query->finish();

        delete query;
        CloseConnection();
    }catch(std::exception &e){
        if(query != nullptr){
            qDebug() << "Null query";
            delete query;
        }

        cout << e.what() << endl;
        CloseConnection();
        throw;
    }

    return table;
}
