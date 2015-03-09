#include "client.h"
#include <QDebug>

Client::Client(QObject *parent) : QObject(parent)
{
    udpReceiver = new UdpReceiver(this);
    connect(udpReceiver,SIGNAL(gotDataFromHost(QHostAddress)),
            this,SLOT(initSslConnection(QHostAddress)));
    qDebug() << "Waiting for udp connection...";
}

Client::~Client()
{

}



void Client::initSslConnection(QHostAddress host)
{
    sslClient = new SslClient(this);
    sslClient->initSslConnection(host);
}
