#ifndef OPERATOR_ASSIGN_H
#define OPERATOR_ASSIGN_H

#include "Statement.h"

//Value Assignment statement class
//The value assignment statement assigns a value to a variable
class OperatorAssign : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	string ArithOp;
	string RHS1;	//Right Handside (Value)
	string RHS2;
	Connector *pOutConn;	//Value Assignment Stat. has one Connector to next statement
	                        //Each statement type in flowchart has a predefined number of (output) connectors
	                        //For example, conditional statement always has 2 output connectors

	                        //Note: We don't need to keep track with input connectors
	                        //      Whenever we want to iterate on all statements of the flowchart
	                        //      we will begin with start statement then its output connector
	                        //      then the connector's destination statement and so on (follow the connectors)

	Point Inlet;	//A point where connections enters this statement 
	                //It's used as the (End) point of the (Input) connectors
	Point Outlet;	//A point a connection leaves this statement
	                //It's used as the (Start) point of the (Output) connector

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();
	
public:
	OperatorAssign(Point Lcorner, string LeftHS = "", string arithop="+" , string RightHS1="", string RightHS2="");
	
	void setLHS(const string &L);
	void setArithOp(string arithop);
	void setRHS1(string R1);
	void setRHS2(string R2);

	virtual void Draw(Output* pOut) const;

	virtual  Point GetStart(Point P);
	virtual  Point GetEnd(Point P);
	virtual bool IsPointOnMe(Point p);

};

#endif