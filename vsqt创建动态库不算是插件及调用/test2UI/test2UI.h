#pragma once

#include "test2ui_global.h"

class TEST2UI_EXPORT test2UI
{
public:
    test2UI();
	static test2UI& Instance() {
		static test2UI instance3;
		return instance3;
	}
	void test2UI::ShowCreate_test2Dlg();
};
