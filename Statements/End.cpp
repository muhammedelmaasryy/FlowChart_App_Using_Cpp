#include "End.h"
#include <sstream>

using namespace std;

End::End(Point Lcorner,string start)
{
	// Note: The LeftHS and RightHS should be validated inside (AddValueAssign) action
	//       before passing it to the constructor of ValueAssign
	string end = end;
	UpdateStatementText();

	LeftCorner = Lcorner;
	
	pOutConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;	
}


void End::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawEnd(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}

//This function should be called when LHS or RHS changes
void End::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << "End" << "";
	Text = T.str();	 
}