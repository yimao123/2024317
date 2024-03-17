#include "createtest2Dlg.h"

createtest2Dlg::createtest2Dlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

createtest2Dlg::~createtest2Dlg()
{
}
void createtest2Dlg::Show()
{
	Init();//初始化
	showNormal();//正常显示

}
void createtest2Dlg::Init()
{
	//设置窗体框架
	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

	//控件初始化

	//信号与槽的连接
}
