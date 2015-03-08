#include "broadcaster.h"
Broadcaster::Broadcaster(QObject *parent) : QObject(parent),broadcasting(true)
{
    udpSocket = new QUdpSocket(this);
    timer = new QTimer(this);
    timer->setInterval(2000);
    timer->start();
    connect(timer,SIGNAL(timeout()),this,SLOT(udpBroadcast()));
}

Broadcaster::~Broadcaster()
{
    udpSocket->disconnectFromHost();
    udpSocket->close();
}

void Broadcaster::udpBroadcast()
{
    if(broadcasting && udpSocket)
    {
        qDebug() << "Broadcasting";
        udpSocket->writeDatagram("",0,QHostAddress::Broadcast,8445);
    }
}
