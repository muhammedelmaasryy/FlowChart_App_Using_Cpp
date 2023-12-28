#include "Select.h"

#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include <sstream>
using namespace std;
Select::Select(ApplicationManager* pAppManager):Action(pAppManager)
{

}

void Select::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();



	pOut->PrintMessage("Please Select a Statement or a Connector");
	pIn->GetPointClicked(p);   //to get the a point on statement or connector
	pOut->ClearStatusBar();
}

void Select::Execute()
{
	Statement* statement = pManager->GetStatement(p);

	if (statement)
	{
		if (statement->IsSelected())
		{
			statement->SetSelected(false);
			pManager->SetSelectedStatement(NULL);
		}
		else if (!statement->IsSelected() && pManager->GetSelectedStatement())
		{

			statement->SetSelected(true);

			pManager->SetSelectedStatement(NULL);

			pManager->SetSelectedStatement(statement);

			pManager->GetSelectedStatement()->SetSelected(false);

		}
		else
			statement->SetSelected(true);
		pManager->SetSelectedStatement(statement);

	}


	Connector* connector = pManager->GetConnector(p);

	if (connector)
	{
		if (connector->IsSelected())
		{
			connector->SetSelected(false);
			pManager->SetSelectedConnector(NULL);
		}
		else if ((!statement->IsSelected()) && (pManager->GetSelectedConnector()))
		{

			statement->SetSelected(true);

			pManager->SetSelectedConnector(NULL);

			pManager->SetSelectedConnector(connector);

			pManager->GetSelectedConnector()->SetSelected(false);

		}
		else
			connector->SetSelected(true);
		pManager->SetSelectedConnector(connector);
	}
}

