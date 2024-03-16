#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->textEdit->resize(300,400);
    m_sock = new QUdpSocket(this);
    bool result=false;
     result = m_sock->bind(QHostAddress::AnyIPv4,5555,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    //
    //bool result = m_sock->bind(QHostAddress::AnyIPv4,5555,QUdpSocket::ShareAddress);
    //加入组播
    result=m_sock->joinMulticastGroup(QHostAddress("224.200.100.109"));
    if(!result)
    {
        return;
    }

    if(result)
    {
        //设置缓冲区
        m_sock->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption,1024*1024*8);
        //链接接收信号槽
        connect(m_sock,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    }
}

Widget::~Widget()
{
    delete ui;
    //断开
    m_sock->disconnect();
    delete m_sock;
}

void Widget::dataReceived()
{
    while (m_sock->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(m_sock->pendingDatagramSize());
        m_sock->readDatagram(datagram.data(),datagram.size());
        //解析协议
        //先转成QString,再转成string
//        QString strQ=QString(datagram);
//        std::string tmp(datagram.data());
//        std::string str=strQ.toStdString();
//        qDebug()<<datagram.data();
        quint16 *tmp=(quint16*)(datagram.data());

//        QString tmp1;
//        tmp=tmp1.prepend(datagram).toStdString();
        quint16 tmp2=*tmp;
        byte2pton(tmp2,tmp2);
        //ui->textEdit->append(datagram);
        ui->textEdit->append(QString::number(tmp2,10));
    }
}
