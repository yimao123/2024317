#pragma once

#include <QtWidgets/QWidget>
#include "ui_testThread.h"

class testThread : public QWidget
{
    Q_OBJECT

public:
    testThread(QWidget *parent = Q_NULLPTR);

private:
    Ui::testThreadClass ui;
};
