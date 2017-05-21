#include "viewengine.h"

ViewEngine::ViewEngine()
{
 CurrentView = NULL;
}



void ViewEngine::Init()
{
    this->load(QUrl(QLatin1String("qrc:/main.qml")));
    Core = new Engine::EngineValues;
    Core->RegisterContext(this->rootContext());
    Core->RegisterControls(this->rootObjects().first());
    Core->getContext()->setContextProperty("_MainCpp",this);
}

void ViewEngine::ShowSettings()
{
   try{
      RunView((void *)(new Settings()));
   }catch(exception ex){
       Core->ShowMessageBox("Error",QString::fromLatin1(ex.what()));
    }
}

void ViewEngine::RunView(void *obj)
{
    if(CurrentView != NULL){
        delete (BaseClass*)CurrentView;
        CurrentView = NULL;
    }

    ((BaseClass *)obj)->Show();

    CurrentView = obj;

}


