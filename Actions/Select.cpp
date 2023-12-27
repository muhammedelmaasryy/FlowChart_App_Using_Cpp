#include"Save.h"


#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
Save::Save(ApplicationManager *pAppManager):Action(pAppManager)
{
}
void Save::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	
	//Read the (Position) parameter

	pOut->PrintMessage("Enter File Name:");
	FileName = pIn->GetString(pOut);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Click anywhere to start SAVING");
	pIn->GetPointClicked(p);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Saving...");
		

	
	//TODO: Ask the user in the status bar to enter the LHS and set the data member

	
	//TODO: Ask the user in the status bar to enter the RHS and set the data member

	//Note: You should validate the LHS to be variable name and RHS to be a value
	//      Call the appropriate functions for this.
}

void Save::Execute()
{
//	ReadActionParameters();
		
	
	//Calculating left corner of assignement statement block

	
	//Save *pAssign = new Save(Corner ,Value);
	//TODO: should set the LHS and RHS of pAssign statement
	//      with the data members set and validated before in ReadActionParameters()

	//pManager->AddStatement(pAssign); // Adds the created statement to application manger's statement list

	/*{
		ReadActionParameters();
		ofstream OutputFile;
		OutputFile.open(FileName, ios::out);
		pManager->SaveAll(OutputFile);
		OutputFile.close();
	}*/
}