#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlPropertyMap>
#include <QTimer>
#include <QQmlContext>
#include <QDebug>

#include "signalblocker.hpp"

int main(int argc, char *argv[])
{
    if (qEnvironmentVariableIsEmpty("QTGLESSTREAM_DISPLAY")) {
        qputenv("QT_QPA_EGLFS_PHYSICAL_WIDTH", QByteArray("213"));
        qputenv("QT_QPA_EGLFS_PHYSICAL_HEIGHT", QByteArray("120"));

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    }

    qmlRegisterType<SignalBlocker>("com.ge.sigblocker", 1, 0, "SignalBlocker");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    QQmlPropertyMap map;
    engine.rootContext()->setContextProperty("dataMap", &map);
    //map.insert("person", QVariantMap{{"name", "john"},{"age", 30}});
    QTimer timer;

    QObject::connect(&timer, &QTimer::timeout, [&](){
    });

    //timer.start(1000);

    engine.load(url);

    return app.exec();
}
