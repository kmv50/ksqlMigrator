#include "settings.h"

Settings::Settings():BaseClass("qrc:/Settings.qml")
{

}

Settings::~Settings()
{

}

void Settings::onLoad()
{
    Core->getContext()->setContextProperty("_SettingsCpp",this);
}

void Settings::Save()
{
    SqlCredentials * Account = new SqlCredentials();
    SqlCredentials * Account2 = new SqlCredentials();
    try{

      Account->setUsuario(Core->findControlbyName("txt_usuario1")->GetText("Usuario invalido"));
      Account->setPassword(Core->findControlbyName("txt_contrasena1")->GetText("Contrasena invalida"));
      Account->setServidor(Core->findControlbyName("txt_Server1")->GetText("Server invalido"));
      //Account->setDBName(Core->findControlbyName("")->GetText("Usuario invalido"));

      Account2->setUsuario(Core->findControlbyName("txt_usuario2")->GetText("Usuario invalido"));
      Account2->setPassword(Core->findControlbyName("txt_contrasena2")->GetText("Contrasena invalida"));
      Account2->setServidor(Core->findControlbyName("txt_Server2")->GetText("Servidor invalido"));
      //Account->setDBName(Core->findControlbyName("")->GetText("Usuario invalido"));
    }catch(exception &ex){
        //Core->ShowMessageBox("Input",QString::fromLocal8Bit(ex.what()));
    }

    delete Account;
    delete Account2;
}

void Settings::TestDatasource1()
{
    SqlCredentials * Account = new SqlCredentials();
    try{
      Account->setUsuario(Core->findControlbyName("txt_usuario1")->GetText("Usuario invalido"));
      Account->setPassword(Core->findControlbyName("txt_contrasena1")->GetText("Contrasena invalida"));
      Account->setServidor(Core->findControlbyName("txt_Server1")->GetText("Server invalido"));

      sql = new KsqlConnector(Account,"DataSource1");
      DbTableMap result = sql->ReadMap("show databases;",{});

      qDebug() << result;
    }catch(exception &ex){
        //Core->ShowMessageBox("Input",QString::fromLocal8Bit(ex.what()));
        if(sql != NULL)
            delete sql;
        delete Account;
         return;
    }

    delete sql;
    delete Account;
}
