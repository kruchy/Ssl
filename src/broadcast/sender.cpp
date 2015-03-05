
#include <iostream>
#include <QtWidgets>
#include <QtNetwork>

#include "sender.h"

Sender::Sender(QObject *parent)
    : QObject(parent)
{
    qDebug() << "Ready to broadcast datagrams on port 45454";

    timer = new QTimer(this);
    udpSocket = new QUdpSocket(this);
    messageNo = 1;

    connect(timer,SIGNAL(timeout()),this,SLOT(broadcastDatagram()));
    startBroadcasting();
}

void Sender::broadcastDatagram()
{
    timer->start(1000);
}
void Sender::startBroadcasting()
{
    qDebug() << "Now broadcasting datagram "<< messageNo ;
    QByteArray datagram = "Broadcast message " + QByteArray::number(messageNo);
    udpSocket->writeDatagram(datagram.data(),datagram.size(), QHostAddress::Broadcast,45454);
    ++messageNo;
}
