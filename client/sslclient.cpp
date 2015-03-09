#include "sslclient.h"

SslClient::SslClient(QObject *parent):
    QObject(parent)
{
    sslSocket = new QSslSocket(this);
    connect(sslSocket, SIGNAL(encrypted()), this, SLOT(connected()));
    connect(sslSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(sslSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(sslSocket, SIGNAL(sslErrors()),this,SLOT(onSslErrors()));
    qDebug() << "Initiating ssl";
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
    sslSocket->setProtocol(QSsl::SslV3);
    QSslKey ssl_key(key,QSsl::Rsa);
    QSslCertificate ssl_cert(cert);
    sslSocket->setPrivateKey(ssl_key);
    sslSocket->setLocalCertificate(ssl_cert);
}

SslClient::~SslClient()
{

}

void SslClient::onSslErrors()
{
    sslSocket->ignoreSslErrors();
}

void SslClient::initSslConnection(QHostAddress host) {
    sslSocket->setProtocol(QSsl::SslV3);
    sslSocket->connectToHostEncrypted(host.toString(), 8445);
}


void SslClient::connected() {
    qDebug() << "Connected to host";
}

void SslClient::disconnected() {
    qDebug() << "Disconnected";
}

void SslClient::readyRead() {
    qDebug() << sslSocket->readAll().data();
    handleData(sslSocket->readAll().data());
}

void SslClient::handleData(QString str) {
    if("USER" == str.mid(0,4)) {
        qDebug() << "Username:" << str.mid(5);
    }
    else if ("PASS" == str.mid(0,4)) {
        qDebug() << "Password:" << str.mid(5);
    }
}
