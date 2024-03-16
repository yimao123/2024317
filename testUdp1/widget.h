#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include <string>
#define byte2pton(net,post)\
{\
    net=(post>>8)|(post<<8);\
}
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void dataReceived();

private:
    Ui::Widget *ui;
    QUdpSocket *m_sock;
};

#endif // WIDGET_H
