#include "test2UI.h"
#include "createtest2Dlg.h"
createtest2Dlg *gpRigidCellDlg = NULL;
test2UI::test2UI()
{
	gpRigidCellDlg = new createtest2Dlg();
}
void test2UI::ShowCreate_test2Dlg()
{
	gpRigidCellDlg->show();
}
