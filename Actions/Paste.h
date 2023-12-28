#ifndef PASTE_H
#define PASTE_H

#include "Action.h"
#include "../ApplicationManager.h"

class Paste :public Action {
	Point p;
public:
	Paste(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();
};
#endif