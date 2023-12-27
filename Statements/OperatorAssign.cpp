#include "OperatorAssign.h"
#include <sstream>

using namespace std;

OperatorAssign::OperatorAssign(Point Lcorner, string LeftHS,string arithop ,string RightHS1,string RightHS2)
{
	// Note: The LeftHS and RightHS should be validated inside (AddValueAssign) action
	//       before passing it to the constructor of ValueAssign
	LHS = LeftHS;
	ArithOp = arithop;
	RHS1 = RightHS1;
	RHS2 = RightHS2;

	UpdateStatementText();

	LeftCorner = Lcorner;
	
	pOutConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;	
}

void OperatorAssign::setLHS(const string &L)
{
	LHS = L;
	UpdateStatementText();
}

void OperatorAssign::setArithOp(string arithop)
{
	ArithOp = arithop;
}

void OperatorAssign::setRHS1(string R1)
{
	RHS1 = R1;
	UpdateStatementText();
}

void OperatorAssign::setRHS2(string R2)
{
	RHS2 = R2;
	UpdateStatementText();
}


void OperatorAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}

Point OperatorAssign::GetStart(Point P)
{
	return Outlet;
}

Point OperatorAssign::GetEnd(Point P)
{
	return Inlet;
}

bool OperatorAssign::IsPointOnMe(Point p)
{
	return (p.x >= LeftCorner.x && p.x <= (LeftCorner.x + UI.ASSGN_WDTH))
		&& (p.y >= LeftCorner.y && p.y <= (LeftCorner.y+UI.ASSGN_HI));
}


//This function should be called when LHS or RHS changes
void OperatorAssign::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T<<LHS<<" = "<<RHS1<<ArithOp<<RHS2;	
	Text = T.str();
}