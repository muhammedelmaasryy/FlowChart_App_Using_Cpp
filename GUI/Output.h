#ifndef OUPTUT_H
#define OUPTUT_H

#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();	

	window* CreateWind(int, int, int , int);
	Input* CreateInput(); //Creates a pointer to the Input object	

	void CreateStatusBar(); //Creates status bar

	//TODO: Complete the following 2 functions
	void CreateDesignToolBar();	//Tool bar of the design mode
	void CreateSimulationToolBar(); //Tool bar of the simulation mode

	void ClearStatusBar();	//Clears the status bar
	void ClearToolBar();   //Clears the tool bar
	void ClearDrawArea();	//Clears the drawing area
	void ClearFigure(Point Left, int width, int height);
	void ClearOutputBar(); //Clears the Output bar
	
	void PrintMessage(string msg);	//Prints a message on Status bar
	void PrintDouble(double d);
	void DrawString(const int, const int, const string);  //Writes a string in the specified location

	void DrawDouble(const int iX, const int iY, double Number);


	// -- Statements Drawing Functions
	void DrawAssign(Point Left, int width, int height, string Text, bool Selected=false);
	void DrawInOut(Point Left, int width, int height, string Text, bool Selected);
	void DrawCond(Point Left, int width, int height, string Text, bool Selected);

	void DrawStart(Point Left, int width, int height,string Text, bool Selected);

	void DrawEnd(Point Left, int width, int height,string Text ,bool Selected);
	void DrawConnector(Point Left, int width, int height,string Text, bool Selected);

	void DrawConnector1(Point Left, int width, int height, string Text, bool Selected);

	void DrawConnector2(Point Left, int width, int height, string Text, bool Selected);

	void DrawConnector3(Point Left, int width, int height, string Text, bool Selected);
	//TODO: Add similar functions for drawing all other statements.
	//		e.g. DrawCondtionalStat(......), DrawStart(......), DrawEnd(.......), ...etc
	//		Decide the parameters that should be passed to each of them
	
	//TODO: Add DrawConnector function

	~Output();
};

#endif