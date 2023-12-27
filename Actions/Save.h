#pragma once
#ifndef SAVE_H
#define SAVE_H
#include"Action.h"
#include "../ApplicationManager.h"
#include<fstream>

class Save : public Action
{
private:
	// in the data members of the actions
	// we put the paramaters of the action
	// to be set in ReadActionParameters() then used in Execute()

	string FileName; //for the file name 
	Point p;
public:
	Save(ApplicationManager *pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();
	
	//Create and add an assignemnt statement to the list of statements
	virtual void Execute() ;
	
};

#endif