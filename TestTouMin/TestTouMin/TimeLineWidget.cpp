#include "TimeLineWidget.h"
#include <QPainter>
TimeLineWidget::TimeLineWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setMinimumSize(500, 50);  // 设置最小大小
}

TimeLineWidget::~TimeLineWidget()
{
}
void TimeLineWidget::paintEvent(QPaintEvent *) 
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);  // 抗锯齿

	int width = this->width();
	int height = this->height();
	int start = 0;   // 开始时间
	int end = 100;    // 结束时间
	int hourWidth = width / (end - start);  // 每小时宽度

											// 绘制背景
	painter.fillRect(0, 0, width, height, Qt::white);

	// 绘制时间轴
	painter.setPen(Qt::black);
	painter.drawLine(0, height / 2, width, height / 2);

	// 绘制时间标签和刻度
	painter.setFont(QFont("Arial", 10));
	for (int i = start; i <= end; ++i) {
		QString text = QString::number(i);
		int textWidth = painter.fontMetrics().width(text);
		painter.drawText(i * hourWidth - textWidth / 2, height / 2 - 10, text);
		painter.drawLine(i * hourWidth, height / 2 - 5, i * hourWidth, height / 2 + 5);
	}

	// 绘制起始时间和结束时间标记
	painter.setPen(Qt::red);
	painter.drawText(start * hourWidth, height / 2 + 20, QString::number(start));
	painter.drawText(end * hourWidth, height / 2 + 20, QString::number(end));
	painter.drawLine(start * hourWidth, height / 2 - 20, start * hourWidth, height / 2 + 20);
	painter.drawLine(end * hourWidth, height / 2 - 20, end * hourWidth, height / 2 + 20);
}
