#include "ApplicationManager.h"
#include "Actions\AddValueAssign.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Actions\AddCond.h"
#include "Actions/AddStart.h"
#include"Actions/AddEnd.h"
#include"Actions\AddConnector.h"
#include "Actions/AddVariableAssign.h"
#include"Actions/AddRead.h"
#include "Actions/AddWrite.h"
#include "Actions/AddOperatorAssign.h"
using namespace std;
#include <iostream>

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	StatCount = 0;
	ConnCount = 0;
	pSelectedStat = NULL;	//no Statement is selected yet
	pClipboard = NULL;
	
	//Create an array of Statement pointers and set them to NULL		
	for(int i=0; i<MaxCount; i++)
	{
		StatList[i] = NULL;	
		ConnList[i] = NULL;
	}
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//


ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	Connector* Connect = NULL;
	Statement* Src = NULL;
	Statement* Dst = NULL;
	
	//According to ActioType, create the corresponding action object
	switch (ActType)
	{
		case ADD_VALUE_ASSIGN:
			pAct = new AddValueAssign(this);
			break;

		case ADD_CONDITION:
			///create AddCondition Action here
			pAct = new AddCond(this);
			break;
		case ADD_START:
			pAct = new AddStart(this);
			break;
		case ADD_END:
			pAct = new AddEnd(this);
			break;
		case ADD_VAR_ASSIGN:
			pAct = new AddVariableAssign(this);
			break;
		case ADD_OPER_ASSIGN:
			pAct = new AddOperatorAssign(this);
			break;
		case ADD_READ:
			pAct = new AddRead(this);
			break;
		case ADD_WRITE:
			pAct = new AddWrite(this);
			break;
		case ADD_CONNECTOR:
			pAct = new AddConn(this);
			break;
		case SELECT:
			///create Select Action here

			break;

		case SAVE:
		//	pAct = new SAVE(this);
			//break;

		case SWITCH_SIM_MODE:
			pOut->PrintMessage("Action: Switch to Simulation Mode, creating simualtion tool bar");
			pOut->ClearToolBar();
			pOut->ClearDrawArea();
			pOut->CreateSimulationToolBar();
			break;
		case SWITCH_DSN_MODE:

			pOut->PrintMessage("Action: Switch to Design Mode, creating Design tool bar");
			pOut->ClearToolBar();
			pOut->ClearDrawArea();
			pOut->CreateDesignToolBar();
			break;
		case EXIT:


			///create Exit Action here
			
			break;
		
		case STATUS:
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
	}
}



//==================================================================================//
//						Statements Management Functions								//
//==================================================================================//


//Add a statement to the list of statements
void ApplicationManager::AddStatement(Statement *pStat)
{
	if(StatCount < MaxCount)
		StatList[StatCount++] = pStat;
	
}

////////////////////////////////////////////////////////////////////////////////////
Statement *ApplicationManager::GetStatement(Point P) const
{
	for (int i = 0; i < StatCount; i++)
		if (StatList[i]->IsPointOnMe(P))
			return StatList[i];

	///Add your code here to search for a statement given a point P(x,y)	
	///WITHOUT breaking class responsibilities

	return NULL;
}
void ApplicationManager::AddConnector(Connector* pConn)
{
	if (ConnCount < MaxCount)
		ConnList[ConnCount++] = pConn;
}
Connector* ApplicationManager::GetConnector(Point P) const
{

	for (int i = 0; i < ConnCount; i++)
		if (ConnList[i]->IsPointOnMe(P))
			return ConnList[i];
	
	return NULL;
}
void ApplicationManager::SaveAll(ofstream& Outputfile)
{
	Outputfile << StatCount[i] << endl;
	for (int i = 0; i < StatCount; i++) {
		StatList[i]->Save(Outputfile);
	}
	Outputfile << ConnCount[i] << endl;
	for (int i = 0; i < ConnCount; i++) {
		ConnList[i]->Save(Outputfile);
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Returns the selected statement
Statement *ApplicationManager::GetSelectedStatement() const
{	return pSelectedStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the statement selected by the user
void ApplicationManager::SetSelectedStatement(Statement *pStat)
{	pSelectedStat = pStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Returns the Clipboard
Statement *ApplicationManager::GetClipboard() const
{	return pClipboard;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the Clipboard
void ApplicationManager::SetClipboard(Statement *pStat)
{	pClipboard = pStat;	}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//


//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();

	//Draw all statements
	for(int i=0; i<StatCount; i++)
		StatList[i]->Draw(pOut);
	
	//Draw all connections
	for(int i=0; i<ConnCount; i++)
		ConnList[i]->Draw(pOut);

}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////


//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<StatCount; i++)
		delete StatList[i];
	for(int i=0; i<StatCount; i++)
		delete ConnList[i];
	delete pIn;
	delete pOut;
	
}
