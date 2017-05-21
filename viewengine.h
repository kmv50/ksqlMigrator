#ifndef VIEWENGINE_H
#define VIEWENGINE_H
#include <enginevalues.h>
#include <settings.h>

extern Engine::EngineValues * Core;

class ViewEngine: public QQmlApplicationEngine
{
    Q_OBJECT
public:
    explicit ViewEngine();
    void Init();
public slots:
    void ShowSettings();
private:
    void *CurrentView;
    void RunView(void *obj);
};

#endif // VIEWENGINE_H
