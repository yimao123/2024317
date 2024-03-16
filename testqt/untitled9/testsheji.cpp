#include "testsheji.h"
#include "ui_testsheji.h"

TestSheji::TestSheji(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestSheji)
{
    ui->setupUi(this);
}

TestSheji::~TestSheji()
{
    delete ui;
}
