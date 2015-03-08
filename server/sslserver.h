#ifndef SSLSERVER_H
#define SSLSERVER_H
#include <QSslSocket>
#include <QObject>
#include <QTcpServer>
class SslServer :public QObject
{
    Q_OBJECT
public:
    SslServer(QObject * parent = 0);
    ~SslServer();

public slots:
    void newConnection();
signals:
private:
    QSslSocket * sslServer;
    QTcpServer * tcpServer;
    void writeToSsl(QSslSocket * socket, char * str);
    void incomingConnection(int socketDescriptor);
    void checkListeningForConnections();
};

#endif // SSLSERVER_H
