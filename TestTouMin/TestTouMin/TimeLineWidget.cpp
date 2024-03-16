#include "TimeLineWidget.h"
#include <QPainter>
TimeLineWidget::TimeLineWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setMinimumSize(500, 50);  // ������С��С
}

TimeLineWidget::~TimeLineWidget()
{
}
void TimeLineWidget::paintEvent(QPaintEvent *) 
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);  // �����

	int width = this->width();
	int height = this->height();
	int start = 0;   // ��ʼʱ��
	int end = 100;    // ����ʱ��
	int hourWidth = width / (end - start);  // ÿСʱ���

											// ���Ʊ���
	painter.fillRect(0, 0, width, height, Qt::white);

	// ����ʱ����
	painter.setPen(Qt::black);
	painter.drawLine(0, height / 2, width, height / 2);

	// ����ʱ���ǩ�Ϳ̶�
	painter.setFont(QFont("Arial", 10));
	for (int i = start; i <= end; ++i) {
		QString text = QString::number(i);
		int textWidth = painter.fontMetrics().width(text);
		painter.drawText(i * hourWidth - textWidth / 2, height / 2 - 10, text);
		painter.drawLine(i * hourWidth, height / 2 - 5, i * hourWidth, height / 2 + 5);
	}

	// ������ʼʱ��ͽ���ʱ����
	painter.setPen(Qt::red);
	painter.drawText(start * hourWidth, height / 2 + 20, QString::number(start));
	painter.drawText(end * hourWidth, height / 2 + 20, QString::number(end));
	painter.drawLine(start * hourWidth, height / 2 - 20, start * hourWidth, height / 2 + 20);
	painter.drawLine(end * hourWidth, height / 2 - 20, end * hourWidth, height / 2 + 20);
}
