#include "udpReceiver.h"

UdpReceiver::UdpReceiver(QObject *parent) :
    QObject(parent),
    receiving(true)
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(8445,QUdpSocket::ShareAddress);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(udpReadyRead()));
    qDebug() << "Waiting for udp connection";
}

UdpReceiver::~UdpReceiver()
{

}

void UdpReceiver::udpReadyRead()
{
    QByteArray data;
    QHostAddress host;
    while(receiving && udpSocket->hasPendingDatagrams())
    {
        data.resize(udpSocket->pendingDatagramSize());

        udpSocket->readDatagram(data.data(), data.size(), &host);
        qDebug() << "Got data from:" << host.toString();
        receiving = false;
        udpSocket->close();
        emit gotDataFromHost(host);
    }
}
