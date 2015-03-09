#include "client.h"
#include <QDebug>

Sherlybox::Sherlybox(QObject *parent) : QObject(parent),receiving(true)
{
    sslSocket = new QSslSocket(this);
    connect(sslSocket, SIGNAL(encrypted()), this, SLOT(connected()));
    connect(sslSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(sslSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));
    connect(sslSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(8445, QUdpSocket::ShareAddress);
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(udpReadyRead()));

    qDebug() << "Waiting for udp connection...";
}

Sherlybox::~Sherlybox()
{

}


void Sherlybox::udpReadyRead() {
    while(receiving && udpSocket->hasPendingDatagrams() ) {
        QByteArray data;
        QHostAddress host;
        data.resize(udpSocket->pendingDatagramSize());

        udpSocket->readDatagram(data.data(), data.size(), &host);
        qDebug() << "Got data from:" << host.toString();
        receiving = false;
        udpSocket->close();
        initSslConnection(host);
    }
}

void Sherlybox::initSslConnection(QHostAddress host) {
    sslSocket->setProtocol(QSsl::TlsV1_1);
    sslSocket->connectToHostEncrypted(host.toString(), 8445);
}


void Sherlybox::connected() {
    qDebug() << "Connected to host";
}

void Sherlybox::disconnected() {
    qDebug() << "Disconnected";
}

void Sherlybox::bytesWritten(qint64 bytes) {

}


void Sherlybox::readyRead() {
    qDebug() << sslSocket->readAll().data();
    handleData(sslSocket->readAll().data());
}


void Sherlybox::handleData(QString str) {
    if("USER" == str.mid(0,4)) {
        qDebug() << "Username:" << str.mid(5);
    }
    else if ("PASS" == str.mid(0,4)) {
        qDebug() << "Password:" << str.mid(5);
    }
}
