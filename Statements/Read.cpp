#include "Read.h"
#include <sstream>

using namespace std;

Read::Read(Point Lcorner, string Variable)
{
	// Note: The LeftHS and RightHS should be validated inside (AddValueAssign) action
	//       before passing it to the constructor of ValueAssign
	Variable = Variable;

	UpdateStatementText();

	LeftCorner = Lcorner;
	
	pOutConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;	
}


void Read::setVariable( string& Variable)
{
	Variable = Variable;
	UpdateStatementText();
}



void Read::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawInOut(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}

Point Read::GetStart()
{
	return Outlet;
}

Point Read::GetEnd()
{
	return Inlet;
}

bool Read::IsPointOnMe(Point p)
{
	return (p.x >= LeftCorner.x && p.x <= (LeftCorner.x + UI.ASSGN_WDTH)&&p.x>=LeftCorner.x-UI.ASSGN_WDTH/2)
		&& (p.y >= LeftCorner.y && p.y <= (LeftCorner.y+UI.ASSGN_HI));
}


//This function should be called when LHS or RHS changes
void Read::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T<<"" << Variable <<"";
	Text = T.str();
}