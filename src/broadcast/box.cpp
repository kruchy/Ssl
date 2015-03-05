
#include <iostream>
#include <QtWidgets>
#include <QtNetwork>
#include "box.h"

Sender::Sender(QObject *parent)
    : QObject(parent)
{
    qDebug() << "Ready to broadcast datagrams on port 45454";
    messageNo = 1;

    udpSocket = new QUdpSocket(this);

    udpSocket->bind(45454);
    connect(udpSocket,SIGNAL(readyRead()),SLOT(processPendingDatagrams()));qDebug() << "box" ;
    connect(this,SIGNAL(setAddress()),SLOT(sslConnection()));
    startBroadcasting();

}

void Sender::broadcast()
{

}

void Sender::startBroadcasting()
{
    qDebug() << "Now broadcasting datagram "<< messageNo;
    QByteArray datagram = "Broadcast message " + QByteArray::number(messageNo);
    udpSocket->writeDatagram(datagram.data(),datagram.size(), QHostAddress::Broadcast,45454);
    ++messageNo;
}

void Sender::processPendingDatagrams()
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
        appAddress = sender.toString();
        emit setAddress();
    }
}


void Sender::sslConnection() {
    socket = new QSslSocket;
    if(!QSslSocket::supportsSsl()) {
        qDebug() << "SSL is not supported";
        return;
    }

//    QString hostname = "192.168.207.121";


    qDebug() << "wchodzi";
    socket->connectToHostEncrypted(appAddress,45454);
    qDebug() <<socket->isEncrypted();


    qDebug() << "wyszlo";
   // socket->write("3"); // 3 means that we should press the button 3 times

//    while(socket->waitForReadyRead(1000)) {
//        qDebug() << socket->readAll().data();
//    }
//    qDebug() << "End of SSL connection";
}
