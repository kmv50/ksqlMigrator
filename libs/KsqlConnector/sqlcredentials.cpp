#include "sqlcredentials.h"



QString SqlCredentials::getPassword() const
{
return Password;
}

void SqlCredentials::setPassword(const QString &value)
{
Password = value;
}

QString SqlCredentials::getServidor() const
{
return Servidor;
}

void SqlCredentials::setServidor(const QString &value)
{
Servidor = value;
}

QString SqlCredentials::getDBName() const
{
return DBName;
}

void SqlCredentials::setDBName(const QString &value)
{
DBName = value;
}

QString SqlCredentials::getUsuario() const
{
return Usuario;
}

void SqlCredentials::setUsuario(const QString &value)
{
Usuario = value;
}
