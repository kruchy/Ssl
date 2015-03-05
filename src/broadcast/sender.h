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

private:
    QUdpSocket *udpSocket;
    int messageNo;
};


#endif
