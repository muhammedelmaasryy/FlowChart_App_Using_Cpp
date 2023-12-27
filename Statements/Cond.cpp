#include "Cond.h"
#include <sstream>

using namespace std;

Cond::Cond(Point Top, string LeftHS,string Cop, string RightHS)
{
	// Note: The LeftHS and RightHS should be validated inside (AddValueAssign) action
	//       before passing it to the constructor of ValueAssign
	LHS = LeftHS;
	CompOp = Cop;
	RHS = RightHS;

	UpdateStatementText();

	TopCorner = Top;
	
	pOutConn1 = NULL;	//No connectors yet
	pOutConn2 = NULL;

	Inlet.x = TopCorner.x;
	Inlet.y = TopCorner.y;

	Outlet1.x = TopCorner.x+ UI.ASSGN_WDTH;
	Outlet1.y = TopCorner.y + UI.ASSGN_HI;
	
	Outlet2.x = TopCorner.x - UI.ASSGN_WDTH;
	Outlet2.y = TopCorner.y + UI.ASSGN_HI;
}

void Cond::setLHS(const string &L)
{
	LHS = L;
	UpdateStatementText();
}

void Cond::setCompOp(string Cop)
{
	CompOp = Cop;
	UpdateStatementText();
}

void Cond::setRHS(string R)
{
	RHS = R;
	UpdateStatementText();
}




Point Cond::GetStart(Point inlet)
{

	if (inlet.x <= TopCorner.x)
		return Outlet2;
	else
		return Outlet1;
}

Point Cond::GetEnd(Point p)
{
	return Inlet;
}

bool Cond::IsPointOnMe(Point p)
{
	return (p.x >= (TopCorner.x-UI.ASSGN_WDTH) && p.x <= (TopCorner.x + UI.ASSGN_WDTH))
		&& (p.y >= TopCorner.y && p.y <= (TopCorner.y + 2*UI.ASSGN_HI));
}

void Cond::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawCond(TopCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}


//This function should be called when LHS or RHS changes
void Cond::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T<<LHS<<CompOp<<RHS;	
	Text = T.str();	 
}
