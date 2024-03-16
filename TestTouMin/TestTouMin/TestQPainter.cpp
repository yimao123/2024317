#include "TestQPainter.h"

TestQPainter::TestQPainter(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

TestQPainter::~TestQPainter()
{
}
void TestQPainter::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.setOpacity(0.5);
	QColor color(255, 150, 30);
	painter.setBrush(color);
	//painter.drawRect(this->rect());
	QRect rec(0, 0, this->width(), this->height() / 5);
	painter.drawRect(rec);
}