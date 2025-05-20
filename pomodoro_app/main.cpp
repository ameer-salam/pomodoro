#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QList>
#include <QObject>
#include <QDebug>

#include "pomodoro.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //engine to load and execute the QML code
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject *uiWindow = nullptr;        //to obtain the pointer to the root object
    //declared outside of try to have its scope outside of the try block



    //exception handling for rooting
    //extracting the root element of the QML
    try{
        const QList <QObject *> rootObject = engine.rootObjects(); //this is a QList of the root objects
        //the scope of the rootobject list is limiited to the try block

        if(rootObject.isEmpty()){           //this is to check if the list is empty
            throw std::runtime_error("The root object was not found");
        }

        uiWindow = rootObject.first(); //root to the first root element

        if(!uiWindow)
        {
            throw std::runtime_error("The Qobject pointer to the UI Window is Null");
        }

        else
        {
            qDebug()<<"The mainWindow for the UI has been loaded";
        }
    }

    catch(const std::exception &e)
    {
        qWarning()<<"Error occured during the UI loading : "<<e.what();
    }


    Pomodoro *pomodor = new Pomodoro(0, uiWindow);


    return app.exec();
}
