#include "QtWidgetsApplication12.h"

QtWidgetsApplication12::QtWidgetsApplication12(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

	connect(ui.DoBtn, SIGNAL(clicked()), this, SLOT(OnClickDoBtn()));
}
void QtWidgetsApplication12::OnClickDoBtn()
{
	test2UI::Instance().ShowCreate_test2Dlg();
}
