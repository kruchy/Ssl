#include <iostream>
#include <QtNetwork>
#include "receiver.h"

Receiver::Receiver(QObject *parent) :
    QObject(parent), port(45454)
{
    qDebug() << "Listening for broadcasting messages";

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(port, QUdpSocket::ShareAddress);

    //connect(udpSocket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
  //  sslConnection();
}

void Receiver::processPendingDatagrams()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        QHostAddress sender;

        // resize datagram to be capable to handle incoming data
        int datagramSize = udpSocket->pendingDatagramSize();
        datagram.resize(datagramSize);

        // get needed data from the packet
        udpSocket->readDatagram(datagram.data(),
                                datagram.size(),
                                &sender);

        qDebug() << "Received datagram: " << datagram.data();
        qDebug() << "From: " << sender.toString();
    }
}


void Receiver::sslConnection() {

    if(!QSslSocket::supportsSsl()) {
        qDebug() << "SSL is not supported";
    }

    QSslSocket socket;
    QString hostname = "192.168.207.121";

    socket.connectToHostEncrypted(hostname, port);

    if(!socket.waitForEncrypted(1000)) {
        qDebug() << "waitForEncrypted() timeout";
        return;
    }

    socket.write("3"); // 3 means that we should press the button 3 times

    while(socket.waitForReadyRead(1000)) {
        qDebug() << socket.readAll().data();
    }

    qDebug() << "End of SSL connection";
}

