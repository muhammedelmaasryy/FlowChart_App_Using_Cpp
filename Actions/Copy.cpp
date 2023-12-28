#include "Copy.h"
#include "../ApplicationManager.h"
#include "Action.h"
#include <sstream>
using namespace std;


Copy::Copy(ApplicationManager* pAppManager) :Action(pAppManager)
{

}

void Copy::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
   
	
	
	pOut->PrintMessage("Please Select a Statement or a Connector to COPY");
	pIn->GetPointClicked(p);   //to get the a point on statement or connector
	pOut->ClearStatusBar();
}

void Copy::Execute()
{
	
	ReadActionParameters();
	Statement* statement = pManager->GetStatement(p);
	Output *P = pManager->GetOutput();
	Input* pI = pManager->GetInput();

	if (statement)
	{
		
		if (statement->IsSelected())
		{
			if (statement->IsPointOnMe(p))
			{
				pManager->SetClipboard(statement);
				P->PrintMessage("Statement COPIED SUCCESSFULLY!");
				return;
			}
			else
			{
				P->PrintMessage("NO STATEMENT WAS SELECTED");
				return;
			}
		}
	

	}
}
	