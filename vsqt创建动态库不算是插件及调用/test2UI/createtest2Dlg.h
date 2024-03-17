#pragma once

#include <QDialog>
#include "ui_createtest2Dlg.h"

class createtest2Dlg : public QDialog
{
	Q_OBJECT

public:
	createtest2Dlg(QWidget *parent = Q_NULLPTR);
	~createtest2Dlg();
	void Show();

	void Init();
private:
	Ui::createtest2Dlg ui;
};
