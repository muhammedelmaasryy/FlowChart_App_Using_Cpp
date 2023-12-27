#include "AddConnector.h"



#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddConn::AddConn(ApplicationManager *pAppManager):Action(pAppManager)
{}

void AddConn::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	//Read the (Position) parameter
	pOut->PrintMessage("Start Statement: Click Start statement");
	pIn->GetPointClicked(P1);
	Statement* Src = pManager->GetStatement(P1);
	while (!Src) 
	{
		pOut->PrintMessage("Erorr!! Click on valid Start statement");
		pIn->GetPointClicked(P1);
		Src = pManager->GetStatement(P1);
	}
	pOut->PrintMessage("Start Statement: Click End statement");
	pIn->GetPointClicked(P2);
	Statement* Dst = pManager->GetStatement(P2);
	while (!Dst)
	{
		pOut->PrintMessage("Erorr!! Click on valid End statement");
		pIn->GetPointClicked(P2);
		Src = pManager->GetStatement(P2);
	}

	pOut->ClearStatusBar();		

	//TODO: Ask the user in the status bar to enter the RHS and set the data member

	//Note: You should validate the LHS to be variable name and RHS to be a value
	//      Call the appropriate functions for this.
}

void AddConn::Execute()
{
	ReadActionParameters();
	Statement* Src = pManager->GetStatement(P1);
	Statement* Dst = pManager->GetStatement(P2);


	Point Start; 
	Point End;

	End = Dst->GetEnd(End);
	Start = Src->GetStart(End);


	//Calculating left corner of assignement statement block
	//Point Corner;
	//Corner.x = Position.x - UI.ASSGN_WDTH/2;
	//Corner.y = Position.y ;
	

	
	Connector *pAssign = new Connector(Src,Dst,Start,End);
	//TODO: should set the LHS and RHS of pAssign statement
	//      with the data members set and validated before in ReadActionParameters()

	pManager->AddConnector(pAssign); // Adds the created statement to application manger's statement list
}

