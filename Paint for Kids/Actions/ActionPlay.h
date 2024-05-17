#ifndef ACTION_PLAY_H
#define ACTION_PLAY_H
#include "Action.h"


class ActionPlay : public Action
{
public:
	ActionPlay(ApplicationManager* pApp);
	void Execute();

};
#endif