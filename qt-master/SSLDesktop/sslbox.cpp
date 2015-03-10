#include "sslbox.h"
#include "ui_sslbox.h"
#include <QFile>
#include <QSsl>
#include <QSslKey>
#include <QSslCertificate>

SslBox::SslBox(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SslBox),
    m_buttonPresses(0)
{
    ui->setupUi(this);
    this->setWindowTitle("SSL BOX");


    QByteArray key;
    QByteArray cert;
    QFile file_key(":/ssl/server.key");
    if(file_key.open(QIODevice::ReadOnly))
    {
        key = file_key.readAll();
        file_key.close();
    }
    else
    {

        qDebug() << "key "  << file_key.errorString();
    }

    QFile file_cert(":/ssl/server.csr");
    if(file_cert.open(QIODevice::ReadOnly))
    {
        cert = file_cert.readAll();
        file_cert.close();
    }
    else
    {
        qDebug() << "csr " << file_cert.errorString();
    }
    QSslKey ssl_key(key,QSsl::Rsa);
    QSslCertificate ssl_cert(cert);
    m_sslSocket = new QSslSocket(this);
    m_sslSocket->setProtocol(QSsl::SslV3);
    m_sslSocket->addCaCertificate(ssl_cert);
    m_sslSocket->setLocalCertificate(ssl_cert);
    m_sslSocket->setPrivateKey(ssl_key);

    m_sslSocket = new QSslSocket(this);
    connect(m_sslSocket, SIGNAL(encrypted()), this, SLOT(connected()));
    connect(m_sslSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(m_sslSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    m_udpSocket = new QUdpSocket(this);
    connect(m_udpSocket, SIGNAL(readyRead()), this, SLOT(udpReadyRead()));
}


SslBox::~SslBox()
{
    delete ui;
}


void SslBox::connected()
{
    if (!m_sslSocket)
        return;
    logOnTextEdit("TCP: Connected");
}


void SslBox::disconnected()
{
    logOnTextEdit("TCP: Disconnected");
}


void SslBox::readyRead() {
    if (!m_sslSocket)
        return;
    QString str = m_sslSocket->readAll().data();

    if("COUNT" == str.mid(0,5)) {
        logOnTextEdit("TCP: COUNT=" + str.mid(6));
        m_buttonPresses = str.mid(6).toInt();
    }
    else if ("USER" == str.mid(0,4)) {
        logOnTextEdit("TCP: USER=" + str.mid(5));
    }
    else {
        logOnTextEdit("TCP: Not supported message");
    }
}


void SslBox::on_udpListeningButton_clicked()
{
    if(m_udpSocket->state() == QUdpSocket::UnconnectedState) {
        logOnTextEdit("Listening for UDP connection...");
        m_udpSocket->bind(8445, QUdpSocket::ShareAddress);
    }
}


void SslBox::udpReadyRead()
{
    while(m_udpSocket->hasPendingDatagrams()) {
        QByteArray data;
        data.resize(m_udpSocket->pendingDatagramSize());
        m_udpSocket->readDatagram(data.data(), data.size(), &currentServerAddress);
        ui->hostLabel->setText("Server address is:" + currentServerAddress.toString());
        logOnTextEdit("UDP: Got msg");
    }
}


void SslBox::on_initTcpButton_clicked()
{
    if(!currentServerAddress.isNull()) {
        logOnTextEdit("Trying to connect to " + currentServerAddress.toString());
        if(m_sslSocket->state() == QTcpSocket::UnconnectedState) {
            m_sslSocket->connectToHostEncrypted(currentServerAddress.toString(),static_cast<quint16>(8445));
            if(!m_sslSocket->waitForEncrypted())
            {
                qDebug() << "couldn't connect encryption";
            }
        }
    } else {
        logOnTextEdit("There is no server to connect to!");
    }
}


void SslBox::on_pairButton_clicked()
{
    if(m_sslSocket && m_sslSocket->isOpen()) {
        if(m_buttonPresses > 0) {
            m_buttonPresses--;
            m_sslSocket->write("BUTTON_PRESSED");
            logOnTextEdit("There is " + QString::number(m_buttonPresses) + " left");
        } else {
            logOnTextEdit("TCP: You should stop pressing that button");
        }
    } else {
        logOnTextEdit("TCP: There is no connection!");
    }
}


void SslBox::logOnTextEdit(QString string)
{
    QTextCursor cursor = ui->logTextEdit->textCursor();
    cursor.insertText(string + "\n");
    cursor.movePosition(QTextCursor::End);
    ui->logTextEdit->setTextCursor(cursor);
}

