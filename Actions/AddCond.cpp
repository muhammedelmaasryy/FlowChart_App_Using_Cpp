#include"AddCond.h"

#include"Action.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
#include "../Statements/Cond.h"
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddCond::AddCond(ApplicationManager *pAppManager):Action(pAppManager)
{}

void AddCond::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	
	//Read the (Position) parameter
	pOut->PrintMessage("Conditional Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();		


	LHS=pIn->GetVariable(pOut);

	
	CompOp = pIn->GetCompOperator(pOut);


	//TODO: Ask the user in the status bar to enter the LHS and set the data member

	
	RHS = pIn->GetValue(pOut);

	pOut->PrintMessage("Click to draw the statement");
	pIn->GetPointClicked(Position);
	//TODO: Ask the user in the status bar to enter the RHS and set the data member

	//Note: You should validate the LHS to be variable name and RHS to be a value
	//      Call the appropriate functions for this.
}

void AddCond::Execute()
{
	ReadActionParameters();
		
	
	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH/2;
	Corner.y = Position.y ;
	
	Cond *pAssign = new Cond(Corner,LHS, CompOp,RHS);
	//TODO: should set the LHS and RHS of pAssign statement
	//      with the data members set and validated before in ReadActionParameters()

	pManager->AddStatement(pAssign); // Adds the created statement to application manger's statement list
}

