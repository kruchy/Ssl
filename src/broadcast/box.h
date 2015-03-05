#ifndef SENDER_H
#define SENDER_H

#include <QtWidgets>
#include "src/connector.h"
#include <QtNetwork>
class QUdpSocket;

class Sender : public QObject
{
 Q_OBJECT

public:
    Sender(QObject *parent = 0);

private slots:
    void startBroadcasting();
    void broadcast();
    void processPendingDatagrams();
    void sslConnection();
signals:
    void setAddress();

private:
    QUdpSocket *udpSocket;
    int messageNo;
    QSslSocket *socket;
    QString appAddress;
};


#endif
