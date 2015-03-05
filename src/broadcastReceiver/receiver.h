#ifndef RECEIVER_H
#define RECEIVER_H

#include <QDialog>
#include <QtNetwork>

class Receiver : public QObject
{
    Q_OBJECT

public:
    Receiver(QObject *parent = 0);

private slots:
    void processPendingDatagrams();

private:
    QUdpSocket *udpSocket;

};

#endif // RECEIVER_H
