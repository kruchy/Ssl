#ifndef SSLSERVER_H
#define SSLSERVER_H

#include <QTcpServer>
#include <QSslSocket>

class sslServer : public QTcpServer
{
    Q_OBJECT
public:
    sslServer(QObject *parent = 0);
    ~sslServer();
    void close();
    quint64 write(QByteArray array,int);
    bool flush();
    bool waitForBytesWritten(int msecs = 30000);
    void sslError(QList<QSslError> list);
    void setButtonPresses(int press);

protected:
    void incommingConnection(qintptr handle);

public slots:
    void clientRead();
    void clientEncrypted();
    void onSslError(QList<QSslError> list);
    void sockerError(QAbstractSocket::SocketError);
signals:
    void logText(QString string);
    void readyRead();

private:
    QSslSocket * sslSocket;
    int m_buttonPresses ;
};

#endif // SSLSERVER_H
