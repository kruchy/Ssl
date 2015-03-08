#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QTcpServer>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QSslSocket>

#include <broadcaster.h>
#include <sslserver.h>


class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    ~Server();

signals:

public slots:

private:
    SslServer * sslServer;
    Broadcaster * broadcaster;
    quint16 port;
    void sslError(QList<QSslError> list);

};

#endif
