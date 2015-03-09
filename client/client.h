#ifndef SHERLYBOX_H
#define SHERLYBOX_H

#include <QObject>
#include <QUdpSocket>
#include <QTcpSocket>
#include <QTimer>
#include <QSslSocket>

class Sherlybox : public QObject
{
    Q_OBJECT
public:
    explicit Sherlybox(QObject *parent = 0);
    ~Sherlybox();

signals:

public slots:
    void udpReadyRead();

    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();

private:
    QUdpSocket * udpSocket;
    QSslSocket * sslSocket;
    QTimer * timer;
    bool receiving;
    //void incomingConnection(int socketDescriptor)
    void initSslConnection(QHostAddress host);
    void handleData(QString str);

};

#endif // SHERLYBOX_H
