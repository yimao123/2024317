#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtWidgetsApplication12.h"
#include "test2UI.h"

class QtWidgetsApplication12 : public QWidget
{
    Q_OBJECT

public:
    QtWidgetsApplication12(QWidget *parent = Q_NULLPTR);

	public slots:
	void OnClickDoBtn();
private:
    Ui::QtWidgetsApplication12Class ui;
};
