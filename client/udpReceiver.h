#ifndef BROADCASTER_H
#define BROADCASTER_H

#include <QObject>
#include <QUdpSocket>
#include <QSslSocket>

class UdpReceiver : public QObject
{
    Q_OBJECT

public:
    UdpReceiver(QObject *parent = 0);
    ~UdpReceiver();
public slots:
    void udpReadyRead();

signals:
    void gotDataFromHost(QHostAddress);
private:
    QUdpSocket * udpSocket;
    QSslSocket * sslSocket;
    bool receiving;

};

#endif // BROADCASTER_H
