#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "launcher.h"

int main(int argc, char *argv[])
{
    Launcher launcher;

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QQmlContext* ctx = engine.rootContext();
    ctx->setContextProperty("adbLauncher", &launcher);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));



    return app.exec();
}
