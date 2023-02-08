#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <test_klasse.h>
// #include "qdebug.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    TestKlasse tk;
    tk.setTest(false);
    qDebug() << "m_test: " << tk.getTest();

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/workshop_test_project/main.qml"_qs);
    QObject::connect(
            &engine, &QQmlApplicationEngine::objectCreated, &app,
            [url](QObject *obj, const QUrl &objUrl) {
                if (!obj && url == objUrl)
                    QCoreApplication::exit(-1);
            },
            Qt::QueuedConnection);
    engine.load(url);

    // Embedding C++ Objects into QML with Context Properties
    QQmlContext *ctx = engine.rootContext();
    ctx->setContextProperty("TestKlasse", &tk);

    return app.exec();
}
