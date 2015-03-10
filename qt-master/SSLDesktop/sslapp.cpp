#include "sslapp.h"
#include "ui_sslapp.h"

#include <QTime>

SslApp::SslApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SslApp),
    m_buttonPresses(0)
{
    ui->setupUi(this);
    this->setWindowTitle("SSL APP");

    qsrand(QTime::currentTime().msec());

    m_udpSocket = new QUdpSocket(this);
    m_tcpServer = new sslServer(this);

}

SslApp::~SslApp()
{
    delete ui;
}

void SslApp::on_startBrodcastButton_clicked()
{
    logOnTextEdit("Broadcasted initial msg");
    QByteArray msg = "INIT";
    m_udpSocket->writeDatagram(msg, msg.size(), QHostAddress::Broadcast, 8445);
}



void SslApp::logOnTextEdit(QString string)
{
    ui->logTextEdit->textCursor().insertText(string + "\n");
}

void SslApp::on_closeConnectionButton_clicked()
{
    if(m_tcpServer) {
        m_tcpServer->close();
        ui->hostsConnectedLabel->setText("NO HOST CONNECTED");
        logOnTextEdit("Connection closed");
        m_tcpServer = NULL;
    }
}

void SslApp::on_pressCountButton_clicked()
{
    if(m_tcpServer) {
        m_buttonPresses = qrand() % 4 + 3;
        qDebug() << "1";
        m_tcpServer->setButtonPresses(m_buttonPresses);
        qDebug() << "2";
        QString count = "COUNT=" + QString::number(m_buttonPresses);
        qDebug() << "3";
        m_tcpServer->write(count.toUtf8(), count.size());
        qDebug() << "4";
        m_tcpServer->flush();
        qDebug() << "5";
        m_tcpServer->waitForBytesWritten(1000);
    }
}
