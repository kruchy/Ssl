#ifndef BROADCASTER_H
#define BROADCASTER_H

#include <QUdpSocket>
#include <QTimer>
#include <QObject>

class Broadcaster : public QObject
{
    Q_OBJECT
public:
    Broadcaster(QObject *parent =0);
    ~Broadcaster();
public slots:
    void udpBroadcast();

private:
    QUdpSocket * udpSocket;
    QTimer * timer;
    bool broadcasting;

 };

#endif // BROADCASTER_H
