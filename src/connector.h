#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>
class Connector : public QObject
{/*
Q_OBJECT
public:
    Connector();
    ~Connector();

private slots:
    void processPendingDatagrams();
    void sslConnection();
protected:
    QUdpSocket *udpSocket;
    QSslSocket *socket,*client;
    uint port;
    void sslConnection();
    void processMessage();*/
};
#endif // CONNECTOR_H
