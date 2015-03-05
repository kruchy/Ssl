#ifndef SENDER_H
#define SENDER_H

#include <QtWidgets>
#include <QtNetwork>
class QTimer;
class QUdpSocket;

class Sender : public QObject
{
 Q_OBJECT

public:
    Sender(QObject *parent = 0);

private slots:
    void startBroadcasting();
    void broadcastDatagram();

private:
    QUdpSocket *udpSocket;
    QTimer *timer;
    int messageNo;
};


#endif
