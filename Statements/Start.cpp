#include "Start.h"
#include <sstream>

using namespace std;

Start::Start(Point Lcorner, string start)
{
	// Note: The LeftHS and RightHS should be validated inside (AddValueAssign) action
	//       before passing it to the constructor of ValueAssign
 start = start;
	UpdateStatementText();

	LeftCorner = Lcorner;

	pOutConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}


void Start::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawStart(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}

//This function should be called when LHS or RHS changes
void Start::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << "Start" << "";
	Text = T.str();
}