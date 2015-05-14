#include "launcher.h"

Launcher::Launcher(QObject *parent) : QObject(parent)
{
    m_camId = "";
    connect(&adbProcess, SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(finishedAdb(int,QProcess::ExitStatus)));
}

void Launcher::callAdb()
{
    adbProcess.start(ADB_COMAND,  QStringList() << "devices");
}

void Launcher::finishedAdb(int code, QProcess::ExitStatus status)
{
    qDebug() << "finish!" << code << " " << status << " " << ADB_COMAND;
    if(code == 0 && status == 0){
        QString str =  QString(adbProcess.readAll());
        QStringList lst = str.split("\n");
        qDebug()<< lst.size();
        if (lst.first() == "List of devices attached "){
            m_camId = lst.at(1).split("\t").at(0);
            emit camIdChanged(m_camId);
        }
    }
}

