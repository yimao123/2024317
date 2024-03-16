#pragma once

#include <QWidget>
#include "ui_TimeLineWidget.h"

class TimeLineWidget : public QWidget
{
	Q_OBJECT

public:
	TimeLineWidget(QWidget *parent = Q_NULLPTR);
	~TimeLineWidget();
	void paintEvent(QPaintEvent *);
private:
	Ui::TimeLineWidget ui;
};
