#include "widget.h"
#include "ui_widget.h"
#include <./Qwt/qwt_plot.h>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QwtPlot *plot =new QwtPlot(this);
}

Widget::~Widget()
{
    delete ui;
}
