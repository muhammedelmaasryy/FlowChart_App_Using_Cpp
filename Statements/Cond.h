#ifndef COND_H
#define COND_H

#include "Statement.h"

//Value Assignment statement class
//The value assignment statement assigns a value to a variable
class Cond : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	string CompOp;
	string RHS;	//Right Handside (Value)
	
	Connector *pOutConn1;	//Value Assignment Stat. has one Connector to next statement
	Connector* pOutConn2;                        //Each statement type in flowchart has a predefined number of (output) connectors
	                        //For example, conditional statement always has 2 output connectors

	                        //Note: We don't need to keep track with input connectors
	                        //      Whenever we want to iterate on all statements of the flowchart
	                        //      we will begin with start statement then its output connector
	                        //      then the connector's destination statement and so on (follow the connectors)

	Point Inlet;	//A point where connections enters this statement 
	                //It's used as the (End) point of the (Input) connectors
	Point Outlet1;	//A point a connection leaves this statement
	Point Outlet2;                //It's used as the (Start) point of the (Output) connector

	Point TopCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();
	
public:
	Cond(Point Top, string LeftHS = "", string Cop = "", string RightHS = 0);
	
	void setLHS(const string &L);
	void setCompOp(string Cop);
	void setRHS(string R);

	virtual Point GetStart(Point P);
	//Point GetEnd();
	virtual Point GetEnd(Point p);
	

	virtual bool IsPointOnMe(Point p);

	virtual void Draw(Output* pOut) const;

};

#endif