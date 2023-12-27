#include "Statement.h"

Statement::Statement()	
{ 
	//TODO: set the ID with a unique value
	Text = "";
	Selected = false;	
	ID = ID + 1;
}
void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }

