#include "Write.h"
#include <sstream>

using namespace std;

Write::Write(Point Lcorner, double value)
{
	// Note: The LeftHS and RightHS should be validated inside (AddValueAssign) action
	//       before passing it to the constructor of ValueAssign
	Value = value;

	UpdateStatementText();

	LeftCorner = Lcorner;
	
	pOutConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;	
}


void Write::setValue( double value)
{
	Value = value;
	UpdateStatementText();
}



void Write::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawInOut(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}

Point Write::GetStart(Point P)
{
	return Outlet;
}

Point Write::GetEnd(Point P)
{
	return Inlet;
}

bool Write::IsPointOnMe(Point p)
{
	return (p.x >= LeftCorner.x && p.x <= (LeftCorner.x + UI.ASSGN_WDTH)&&p.x>=LeftCorner.x-UI.ASSGN_WDTH/2)
		&& (p.y >= LeftCorner.y && p.y <= (LeftCorner.y+UI.ASSGN_HI));
}


//This function should be called when LHS or RHS changes
void Write::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T<<Value << "" << "";
	Text = T.str();
}