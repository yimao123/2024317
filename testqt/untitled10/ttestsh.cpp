#include "ttestsh.h"
#include "ui_ttestsh.h"

TtestSh::TtestSh(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TtestSh)
{
    ui->setupUi(this);
}

TtestSh::~TtestSh()
{
    delete ui;
}
