#ifndef SQLCREDENTIALS_H
#define SQLCREDENTIALS_H
#include <QString>

class SqlCredentials
{
public:
    QString getPassword() const;
    void setPassword(const QString &value);

    QString getServidor() const;
    void setServidor(const QString &value);

    QString getDBName() const;
    void setDBName(const QString &value);

    QString getUsuario() const;
    void setUsuario(const QString &value);

private:
    QString Usuario;
    QString Password;
    QString Servidor;
    QString DBName;
};
#endif // SQLCREDENTIALS_H
