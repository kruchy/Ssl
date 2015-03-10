#include "sslserver.h"
#include <QFile>
#include <QSsl>
#include <QSslKey>
#include <QSslCertificate>

sslServer::sslServer(QObject *parent):
    QTcpServer(parent),
    m_buttonPresses(0)
{

    QByteArray key;
    QByteArray cert;
    QFile file_key(":/ssl/server.key");
    if(file_key.open(QIODevice::ReadOnly))
    {
        key = file_key.readAll();
        file_key.close();
    }
    else
    {

        qDebug() << "key "  << file_key.errorString();
    }

    QFile file_cert(":/ssl/server.csr");
    if(file_cert.open(QIODevice::ReadOnly))
    {
        cert = file_cert.readAll();
        file_cert.close();
    }
    else
    {
        qDebug() << "csr " << file_cert.errorString();
    }
    QSslKey ssl_key(key,QSsl::Rsa);
    QSslCertificate ssl_cert(cert);
    sslSocket = new QSslSocket(this);
    sslSocket->setProtocol(QSsl::SslV3);
    sslSocket->addCaCertificate(ssl_cert);
    sslSocket->setLocalCertificate(ssl_cert);
    sslSocket->setPrivateKey(ssl_key);

    connect(sslSocket,SIGNAL(encrypted()),this,SLOT(clientEncrypted()));
    connect(sslSocket, SIGNAL(sslErrors(QList<QSslError>)),this, SLOT(onSslError(QList<QSslError>)) );
    connect(sslSocket,SIGNAL(error(QAbstractSocket::SocketError),this,SLOT(socketError(QAbstractSocket::SocketError)));
    if(!listen(QHostAddress::Any,8445))
    {
        logText("Server couldn't start");
    }
    else
    {
        logText("Listening SSL" + sslSocket->state());
    }

}

void sslServer::socketError(QAbstractSocket::SocketError )
{
    qDebug() <<  sslSocket->errorString();
}

void sslServer::setButtonPresses(int press)
{
    m_buttonPresses = press;
}

sslServer::~sslServer()
{

}

void sslServer::incommingConnection(qintptr handle)
{
    logText("Incoming connection");
    sslSocket->setSocketDescriptor(handle);
    sslSocket->startServerEncryption();
}


void sslServer::clientEncrypted()
{
    emit logText("Connected via SSL to " + sslSocket->peerAddress().toString());
    connect(sslSocket,SIGNAL(readyRead()),this,SLOT(clientRead()));
}

void sslServer::clientRead()
{
    QString str = sslSocket->readAll().data();
    if("BUTTON_PRESSED" == str.mid(0,14)) {
        m_buttonPresses--;
        if(0 == m_buttonPresses) {
            emit logText("TCP: Devices can be paired now");
        }
        else if (0 < m_buttonPresses) {
            emit logText("TCP: Button has been pressed");
        }
        else {
            emit logText("TCP: You should not get here...");
        }
    }
    else {
        emit logText("Not supported msg: " + str);
    }
}


void sslServer::sslError(QList<QSslError> errors)
{
    sslSocket->ignoreSslErrors();
}

quint64 sslServer::write(QByteArray array,int size)
{
    return sslSocket->write(array);
}

bool sslServer::flush()
{
    return sslSocket->flush();
}

void sslServer::close()
{
    sslSocket->close();
}

bool sslServer::waitForBytesWritten(int msecs)
{
    return sslSocket->waitForBytesWritten(msecs);
}
void sslServer::onSslError(QList<QSslError> list)
{
    foreach (const QSslError &e, list)
        emit logText(e.errorString().append("\n"));
    sslSocket->ignoreSslErrors();
}
