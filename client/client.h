#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include "sslclient.h"
#include "udpReceiver.h"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    ~Client();

signals:

public slots:
    void initSslConnection(QHostAddress host);
private:
    SslClient *sslClient;
    UdpReceiver *udpReceiver;
    void handleData(QString str);
};

#endif
