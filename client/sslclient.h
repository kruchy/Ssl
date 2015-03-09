#ifndef SSLCLIENT_H
#define SSLCLIENT_H

#include <QObject>
#include <QSslSocket>
#include <QHostAddress>
#include <QSsl>
#include <QFile>
#include <QSslCertificate>
#include <QSslKey>

class SslClient : public QObject
{
    Q_OBJECT
public:
    SslClient(QObject *parent = 0);
    ~SslClient();
    void initSslConnection(QHostAddress host);

public slots:
    void connected();
    void disconnected();
    void readyRead();
    void onSslErrors();
signals:
private:

    QSslSocket *sslSocket;
    void handleData(QString str);


};

#endif // SSLCLIENT_H
