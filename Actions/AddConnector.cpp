#include "AddConnector.h"



#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddConnector::AddConnector(ApplicationManager *pAppManager):Action(pAppManager)
{}

void AddConnector::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	
	//Read the (Position) parameter
	pOut->PrintMessage("Start Statement: Click to draw statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();		

	//TODO: Ask the user in the status bar to enter the RHS and set the data member

	//Note: You should validate the LHS to be variable name and RHS to be a value
	//      Call the appropriate functions for this.
}

void AddConnector::Execute()
{
	ReadActionParameters();
		
	
	//Calculating left corner of assignement statement block
	//Point Corner;
	//Corner.x = Position.x - UI.ASSGN_WDTH/2;
	//Corner.y = Position.y ;
	Statement* Src;
	Statement* Dst;

	
	Connector *pAssign = new Connector(Src,Dst);
	//TODO: should set the LHS and RHS of pAssign statement
	//      with the data members set and validated before in ReadActionParameters()

	pManager->AddConnector(pAssign); // Adds the created statement to application manger's statement list
}

