#pragma once
#ifndef ACTION_SAVE_H
#define ACTION_SAVE_H

#include "Action.h"

class SaveAction : public Action
{
	string FileName;
public:
	SaveAction(ApplicationManager* pApp);
	virtual void Execute();
	template<typename T> void saveElement(ofstream& outFile, T t, const int& width, const char& separator);
	//convert color to string
	string colorToString(color c);
};

#endif
