#include "sherly.h"

#include <QThread>

Server::Server(QObject *parent) :
    QObject(parent),
    port(8445)
{
    sslServer = new SslServer(this);
    broadcaster = new Broadcaster(this);

}


Server::~Server()
{
}
void Server::sslError(QList<QSslError> list)
{
    foreach (QSslError it, list) {
        qDebug() << (it).errorString();

    }
}
