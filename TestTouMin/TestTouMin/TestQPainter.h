#pragma once

#include <QWidget>
#include "ui_TestQPainter.h"
#include <QPainter>
class TestQPainter : public QWidget
{
	Q_OBJECT

public:
	TestQPainter(QWidget *parent = Q_NULLPTR);
	~TestQPainter();
	void paintEvent(QPaintEvent *);
private:
	Ui::TestQPainter ui;
	
};
