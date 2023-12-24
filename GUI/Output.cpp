#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1200;
	UI.height = 620;
	UI.wx = 15;
	UI.wy = 15;

	UI.AppMode = DESIGN;    //Design Mode is the default mode

	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;
	UI.DrawingAreaWidth = 0.75 * UI.width;

	UI.DrawColor = BLUE;
	UI.HighlightColor = RED;
	UI.MsgColor = RED;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");
	
	pWind->SetPen(RED,3);
	CreateDesignToolBar();
	CreateStatusBar();
	ClearDrawArea();
	ClearOutputBar();
}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);


}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateDesignToolBar() //Draws the Design Menu
{
	UI.AppMode = DESIGN;	//Design Mode
	
	//fill the tool bar 
		
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in Defs.h ==> enum DrawMenuItem
	string MenuItemImages[DSN_ITM_CNT];
	MenuItemImages[ITM_START] = "images\\Run.jpg";
	MenuItemImages[ITM_END] = "images\\End .jpg";
	MenuItemImages[ITM_VALUE_ASSIGN] = "images\\Assign.jpg";
	MenuItemImages[ITM_VAR_ASSIGN] = "images\\X.jpg";
	MenuItemImages[ITM_OPER_ASSIGN] = "images\\Operator.jpg";
	MenuItemImages[ITM_COND] = "images\\Condition.jpg";
	MenuItemImages[ITM_READ] = "images\\Input.jpg";
	MenuItemImages[ITM_WRITE] = "images\\Output.jpg";
	MenuItemImages[ITM_CONNECTOR] = "images\\Connectors.jpg";
	MenuItemImages[ITM_SELECT] = "images\\Select.jpg";
	MenuItemImages[ITM_EDIT_STAT] = "images\\Edit.jpg";
	MenuItemImages[ITM_DEL] = "images\\Delete.jpg";
	MenuItemImages[ITM_COPY] = "images\\Copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\Cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Paste.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Save1.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Load.jpg";
	MenuItemImages[ITM_SwitchSM] = "images\\Simulation.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Exit.jpg";
	//TODO: Prepare images for each menu item and add it to the list


	//Draw menu item one image at a time
	for (int i = 0; i < DSN_ITM_CNT-1; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	MenuItemImages[ITM_TOOL_BAR] = "images\\Toolbar.jpg";
	pWind->DrawImage(MenuItemImages[ITM_TOOL_BAR], (DSN_ITM_CNT-1)*UI.MenuItemWidth, 0, 100, 50);
}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateSimulationToolBar() //Draws the Simulation Menu
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	
	string MenuItemImages[SIM_ITM_CNT];
	MenuItemImages[ITM_VALIDATE] = "images\\Validate.jpg";
	MenuItemImages[ITM_RUN] = "images\\Run.jpg";
	MenuItemImages[ITM_SWITCH_DSN_MODE] = "images\\Design.jpg";
	
	
	for (int i = 0; i < SIM_ITM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	///TODO: add code to create the simulation tool bar
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
void Output::ClearToolBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0,0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.DrawingAreaWidth, UI.height - UI.StatusBarHeight);
}

void Output::ClearFigure(Point Left,int width,int height)
{
	pWind->SetPen(WHITE, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(Left.x,Left.y, Left.x+ width, Left.y + height);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearOutputBar()
{
	//Create output bar by drawing a filled rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(LIGHTBLUE);
	pWind->DrawRectangle(UI.DrawingAreaWidth, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int) (UI.StatusBarHeight/1.5), msg);
}
void Output::PrintDouble(double d)
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawDouble(10, UI.height - (int)(UI.StatusBarHeight / 1.5),d);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawString(const int iX, const int iY, const string Text)
{
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(iX, iY, Text);
}

void Output::DrawDouble(const int iX, const int iY,double Number)
{
	pWind->SetPen(BLACK, 2);
	pWind->DrawDouble(iX, iY,Number);
}
//////////////////////////////////////////////////////////////////////////////////////////

//======================================================================================//
//								Statements Drawing Functions							//
//======================================================================================//

//Draw assignment statement and write the "Text" on it
void Output::DrawAssign(Point Left, int width, int height, string Text, bool Selected)
{
	if(Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor,3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor,3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);
		
	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x+width/4, Left.y + height/4, Text);
}
void Output::DrawInOut(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawQuad(Left.x, Left.y, Left.x + 3*width/2, Left.y, Left.x +  (width), Left.y + 3*height /4 , Left.x - width /2, Left.y + 3*height /4);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x+width/5, Left.y + height / 4, Text);
}
void Output::DrawCond(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawQuad(Left.x, Left.y, Left.x + width, Left.y + height, Left.x, Left.y + 2*height, Left.x - width, Left.y + height );
	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x-width/2, Left.y + height, Text);
}

void Output::DrawStart(Point Left, int width, int height,string Text, bool Selected)
{
	if (Selected)
		pWind->SetPen(UI.HighlightColor, 3);
	else
		pWind->SetPen(UI.DrawColor, 3);

	pWind->DrawEllipse(Left.x, Left.y, Left.x + width, Left.y + height);

	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width * 0.37, Left.y + height * 0.37, Text);
}
void Output::DrawEnd(Point Left, int width, int height, string Text,bool Selected)
{
	if (Selected)
		pWind->SetPen(UI.HighlightColor, 3);
	else
		pWind->SetPen(UI.DrawColor, 3);

	pWind->DrawEllipse(Left.x, Left.y, Left.x + width, Left.y + height);

	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width * 0.4, Left.y + height * 0.4, Text);
}

void Output::DrawConnector(Point Left, int width, int height,string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the connector line
	pWind->DrawLine(Left.x, Left.y,Left.x +width,Left.y);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x - width / 4, Left.y + height / 4,Text);


	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawTriangle(Left.x+(width+8), Left.y,Left.x+width,Left.y+6,Left.x+width,Left.y-6);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x - width / 3, Left.y + height / 3, Text);
}
void Output::DrawConnector1(Point Left, int width, int height, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the connector line
	pWind->DrawLine(Left.x, Left.y, Left.x, Left.y+height);



	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawTriangle(Left.x, Left.y+(height+8), Left.x +6, Left.y+height, Left.x -6, Left.y + height);
}
void Output::DrawConnector2(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the connector line
	pWind->DrawLine(Left.x, Left.y, Left.x - width, Left.y);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x - width / 4, Left.y + height / 4, Text);


	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawTriangle(Left.x -(width+8), Left.y, Left.x - width, Left.y + 6, Left.x - width, Left.y - 6);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x - width / 3, Left.y + height / 3, Text);
}
void Output::DrawConnector3(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the connector line
	pWind->DrawLine(Left.x, Left.y, Left.x, Left.y - height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x - width / 4, Left.y + height / 4, Text);


	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawTriangle(Left.x, Left.y - (height + 8), Left.x + 6, Left.y - height, Left.x - 6, Left.y - height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x - width / 3, Left.y + height / 3, Text);
}


//TODO: Add similar functions for drawing all other statements.
//		e.g. DrawCondtionalStat(......), DrawStart(......), DrawEnd(.......), ...etc
//		Decide the parameters that should be passed to each of them
	
//TODO: Add DrawConnector function

//////////////////////////////////////////////////////////////////////////////////////////
	Output::~Output()
{
	delete pWind;
}
