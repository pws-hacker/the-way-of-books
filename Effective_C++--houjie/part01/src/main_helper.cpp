#pragma once
#include "include/main_helper.h"

#include "include/class01.h"
#include "include/class02.h"



void PartHelper::excuteClass01()
{
	Class01 class01;
	class01.testMacroError();
	class01.testInlineFunc();
	class01.testConstPoint();
	class01.testClassConstFunc();
	class01.testClassConstVariable();
	class01.testClassConstAndNon_constFunc();
	class01.testCopyAssignment();
}

void PartHelper::excuteClass02()
{
	Class02 class02;
	class02.testClassVirtual();
	class02.testAutoPtr();
	class02.testSharedPtr();
	class02.testGetFunc();
	class02.testNewDeleteArray();
	class02.testNewedSharePtr();


}
