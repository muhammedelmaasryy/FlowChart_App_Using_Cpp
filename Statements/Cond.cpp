#include "Cond.h"
#include <sstream>

using namespace std;

Cond::Cond(Point Lcorner, string LeftHS,string Cop, double RightHS)
{
	// Note: The LeftHS and RightHS should be validated inside (AddValueAssign) action
	//       before passing it to the constructor of ValueAssign
	LHS = LeftHS;
	CompOp = Cop;
	RHS = RightHS;

	UpdateStatementText();

	LeftCorner = Lcorner;
	
	pOutConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;	
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

void Cond::setRHS(double R)
{
	RHS = R;
	UpdateStatementText();
}


void Cond::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawCond(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}


//This function should be called when LHS or RHS changes
void Cond::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T<<LHS<<CompOp<<RHS;	
	Text = T.str();	 
}