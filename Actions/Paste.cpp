#include "Paste.h"
#include "../ApplicationManager.h"
#include "Action.h"
#include <sstream>
using namespace std;


Paste::Paste(ApplicationManager* pAppManager) :Action(pAppManager)
{

}

void Paste::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
   
	
	
	pOut->PrintMessage("Click to PASTE the Statement Copied");
	pIn->GetPointClicked(p);   //to get the a point on statement or connector
	pOut->ClearStatusBar();
}

void Paste::Execute()
{
	
	ReadActionParameters();
	Statement* statement = pManager->GetClipboard();
	Output *P = pManager->GetOutput();
	Input* pI = pManager->GetInput();

	if (statement)
	{
        pManager->AddStatement(statement);
		statement->Draw(P);
		P->PrintMessage("Pasted The Statement");
		return;
	}
	else
	{
		P->PrintMessage("Not PASTED");
		return;
	}
}
	