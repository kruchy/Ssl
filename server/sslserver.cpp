#include "sherly.h"
#include <QTimer>
#include <QFile>
#include <QDir>
SslServer::SslServer(QObject *parent) :
    QObject(parent)
{
    QByteArray key;
    QByteArray cert;
    QFile file_key(QDir::current().path() +  "/server.key");
    if(file_key.open(QIODevice::ReadOnly))
    {
        key = file_key.readAll();
        file_key.close();
    }
    else
    {
        qDebug() << file_key.errorString();
    }

    QFile file_cert(QDir::current().path() + "/server.csr");
    if(file_cert.open(QIODevice::ReadOnly))
    {

        cert = file_cert.readAll();
        file_cert.close();
    }
    else
    {
        qDebug() << file_cert.errorString();
    }
    tcpServer = new QTcpServer(this);
    sslServer = new QSslSocket(this);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
    checkListeningForConnections();
}


SslServer::~SslServer()
{
    sslServer->waitForDisconnected();
    sslServer->close();

}


void SslServer::checkListeningForConnections() {
    if(!tcpServer->listen()) {
        qDebug() << "Server couldn't start";
    } else {
        qDebug() << "Server started";
    }
}



void SslServer::newConnection() {
    incomingConnection(tcpServer->nextPendingConnection()->socketDescriptor());
}

void SslServer::incomingConnection(int descriptor)
{
    if(!sslServer->setSocketDescriptor(descriptor))
    {
        qDebug() << "Could not set  socket descriptor";
        delete sslServer;
        return;
    }
    else
    {

    }

}

