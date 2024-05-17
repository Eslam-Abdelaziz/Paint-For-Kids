#ifndef ACTION_DRAW_H
#define ACTION_DRAW_H
#include "Action.h"


class ActionDraw : public Action
{
public:
	ActionDraw(ApplicationManager* pApp);
	void Execute();

};
#endif