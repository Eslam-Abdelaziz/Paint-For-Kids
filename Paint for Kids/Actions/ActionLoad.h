#pragma once
#pragma once
#pragma once
#include "Action.h"
class ActionLoad : public Action
{
public:
	ActionLoad(ApplicationManager* pApp);
	virtual void Execute();
	color stringToColor(string s);
};

