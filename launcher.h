#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <QObject>
#include <QProcess>
#include <QDebug>

class Launcher : public QObject
{
    Q_OBJECT
    QString m_camId;

    QProcess adbProcess;

public:
    explicit Launcher(QObject *parent = 0);

    Q_INVOKABLE void callAdb();
    Q_PROPERTY(QString camId READ camId  NOTIFY camIdChanged)

    QString camId() const
    {
        return m_camId;
    }

signals:

    void camIdChanged(QString camId);

public slots:
    void finishedAdb(int code,QProcess::ExitStatus status);

};

#endif // LAUNCHER_H
