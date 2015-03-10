#ifndef SSLBOX_H
#define SSLBOX_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QSslSocket>
namespace Ui {
class SslBox;
}

class SslBox : public QMainWindow
{
    Q_OBJECT

public:
    explicit SslBox(QWidget *parent = 0);
    ~SslBox();

    void logOnTextEdit(QString string);

private slots:
    void on_udpListeningButton_clicked();
    void on_initTcpButton_clicked();

    void connected();
    void disconnected();
    void readyRead();

    void udpReadyRead();


    void on_pairButton_clicked();

private:
    Ui::SslBox *ui;
    int m_buttonPresses;
    QSslSocket *m_sslSocket;
    QUdpSocket *m_udpSocket;
    QHostAddress currentServerAddress;
};

#endif // SSLBOX_H
