#include "TestTouMin.h"
#include <QPainter>
TestTouMin::TestTouMin(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	mtestQPainter = new TestQPainter();
	mtestQPainter->setWindowOpacity(0.5);
	mtestQPainter->resize(this->width(), this->height()*2 / 5);
	mtestQPainter->move(0, this->height()*3.5 / 5);
	mtestQPainter->show();


	//ʱ����
	mTimeLineWidget = new TimeLineWidget();


	mTimeLineWidget->show();
}
void TestTouMin::paintEvent(QPaintEvent *)
{
	QPainter painter(this);

	QPixmap pixmap(":/TestTouMin/19_big.jpg");
	painter.drawPixmap(this->rect(), pixmap);

	//���ñ���ͼ��

	//����ʱ��

}