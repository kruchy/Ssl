#ifndef BROADCASTER_H
#define BROADCASTER_H

#include <QUdpSocket>
#include <QTimer>
#include <QObject>

class UdpReceiver : public QObject
{
    Q_OBJECT
public:
    UdpReceiver(QObject *parent =0);
    ~UdpReceiver();
public slots:
    void udpBroadcast();

private:
    QUdpSocket * udpSocket;
    QTimer * timer;
    bool broadcasting;

 };

#endif // BROADCASTER_H
