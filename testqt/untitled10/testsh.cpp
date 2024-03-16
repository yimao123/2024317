#include "testsh.h"
#include "ui_testsh.h"

TestSh::TestSh(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestSh)
{
    ui->setupUi(this);
}

TestSh::~TestSh()
{
    delete ui;
}
