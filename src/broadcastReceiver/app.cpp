#include <iostream>
#include <QtNetwork>
#include "app.h"

Receiver::Receiver(QObject *parent) :
    QObject(parent), port(45454)
{
    qDebug() << "Listening for broadcasting messages";

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(port, QUdpSocket::ShareAddress);
    socket = new QSslSocket(this);
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
    boxAddress = "";
    client = new QSslSocket(this);

}




void Receiver::processPendingDatagrams()
{
    QByteArray datagram;
    QHostAddress sender;
    while(udpSocket->hasPendingDatagrams())
    {

        // resize datagram to be capable to handle incoming data
        int datagramSize = udpSocket->pendingDatagramSize();
        datagram.resize(datagramSize);

        // get needed data from the packet
        udpSocket->readDatagram(datagram.data(),
                                datagram.size(),
                                &sender);

        qDebug() << "Received datagram: " << datagram.data();
        qDebug() << "From: " << sender.toString();
        boxAddress = sender.toString();

    }
    sslConnection();
}


void Receiver::sslConnection() {

    if(!QSslSocket::supportsSsl()) {
        qDebug() << "SSL is not supported";
        return;
    }
    if(boxAddress == "" )
    {
        qDebug() << "could not find address";
    }
    qDebug() << boxAddress;
    if(!socket->waitForEncrypted(15000)) {
        qDebug() << "waitForEncrypted() timeout";
        return;
    }

}

void Receiver::processMessage(QString &message)
{
    if(message.startsWith("CON"))
    {
//        connect();
    }

    if(message.startsWith("PRS"))
    {

    }
    if(message.startsWith("LOG"))
    {

    }
    if(message.contains("PSW"))
    {

    }
}
