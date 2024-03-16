#pragma once

#include <QtWidgets/QWidget>
#include "ui_TestTouMin.h"
#include "TestQPainter.h"
#include "TimeLineWidget.h"
class TestTouMin : public QWidget
{
    Q_OBJECT

public:
    TestTouMin(QWidget *parent = Q_NULLPTR);
	void paintEvent(QPaintEvent *);

private:
    Ui::TestTouMinClass ui;
	TestQPainter *mtestQPainter;
	TimeLineWidget *mTimeLineWidget;
};
