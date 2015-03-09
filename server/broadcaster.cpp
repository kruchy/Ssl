#include "broadcaster.h"
UdpReceiver::UdpReceiver(QObject *parent) : QObject(parent),broadcasting(true)
{
    udpSocket = new QUdpSocket(this);
    timer = new QTimer(this);
    timer->setInterval(2000);
    timer->start();
    connect(timer,SIGNAL(timeout()),this,SLOT(udpBroadcast()));
}

UdpReceiver::~UdpReceiver()
{
    udpSocket->disconnectFromHost();
    udpSocket->close();
}

void UdpReceiver::udpBroadcast()
{
    if(broadcasting && udpSocket)
    {
        qDebug() << "Broadcasting";
        udpSocket->writeDatagram("",0,QHostAddress::Broadcast,8445);
    }
}
