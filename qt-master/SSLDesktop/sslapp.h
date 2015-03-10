#ifndef SSLAPP_H
#define SSLAPP_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QUdpSocket>
#include "sslserver.h"
namespace Ui {
class SslApp;
}

class SslApp : public QMainWindow
{
    Q_OBJECT

public:
    explicit SslApp(QWidget *parent = 0);
    ~SslApp();

    void logOnTextEdit(QString string);


private slots:
    void on_startBrodcastButton_clicked();

    void on_closeConnectionButton_clicked();

    void on_pressCountButton_clicked();

private:
    Ui::SslApp *ui;
    int m_buttonPresses;
    QUdpSocket * m_udpSocket;
    sslServer * m_tcpServer;

};

#endif // SSLAPP_H
