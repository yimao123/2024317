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
	Init();//��ʼ��
	showNormal();//������ʾ

}
void createtest2Dlg::Init()
{
	//���ô�����
	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

	//�ؼ���ʼ��

	//�ź���۵�����
}
