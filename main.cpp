#include <viewengine.h>

Engine::EngineValues * Core;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    Core = NULL;
    ViewEngine p;
    p.Init();

    return app.exec();
}
