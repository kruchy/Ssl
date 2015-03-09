#include "server.h"
#include <QTimer>
#include <QFile>
#include <QDir>
#include <QSsl>
#include <QSslCertificate>
#include <QSslKey>
SslServer::SslServer(QObject *parent) :
    QObject(parent)
{
    QByteArray key;
    QByteArray cert;
    QFile file_key(":/ssl/server.key");
    if(file_key.open(QIODevice::ReadOnly))
    {
        qDebug() << "loaded";
        key = file_key.readAll();
        file_key.close();
    }
    else
    {

        qDebug() << file_key.errorString();
    }

    QFile file_cert(":/ssl/server.csr");
    if(file_cert.open(QIODevice::ReadOnly))
    {
        qDebug() << "loaded";
        cert = file_cert.readAll();
        file_cert.close();
    }
    else
    {
        qDebug() << file_cert.errorString();
    }
    sslServer->setProtocol(QSsl::SslV3);
    QSslKey ssl_key(key,QSsl::Rsa);
    QSslCertificate ssl_cert(cert);
    sslServer->setPrivateKey(ssl_key);
    sslServer->setLocalCertificate(ssl_cert);
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
        qDebug() << "Could not set socket descriptor";
        delete sslServer;
        return;
    }
    else
    {

        writeToSsl();
    }
}


void SslServer::writeToSsl()
{
    while(sslServer->isEncrypted())
    {

    }
}
