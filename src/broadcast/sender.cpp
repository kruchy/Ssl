
#include <iostream>
#include <QtNetwork>

#include "sender.h"

Sender::Sender(QObject *parent)
    : QObject(parent)
{
    qDebug() << "Ready to broadcast datagrams on port 45454";

    udpSocket = new QUdpSocket(this);
    messageNo = 1;

    startBroadcasting();
}

void Sender::broadcastDatagram()
{
}
void Sender::startBroadcasting()
{
    qDebug() << "Now broadcasting datagram "<< messageNo ;
    QByteArray datagram = "Broadcast message " + QByteArray::number(messageNo);
    udpSocket->writeDatagram(datagram.data(),datagram.size(), QHostAddress::Broadcast,45454);
    ++messageNo;
}
