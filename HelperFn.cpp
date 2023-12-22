
#include "HelperFn.h"

bool IsValue (string Double)
{
	// checks if the input string is a double value
	// return true if it's double value, false otherwise

	// Double values can be: 12.5, -12.5, -23, -23. , -23.0 …etc.

	//TODO: complete this function
	bool flag = false;
	for (int i = 0;i < Double.length();i++) {
		if (Double[i] >= 65 && Double[i] <= 90 || Double[i] >= 97 && Double[i] <= 122 || Double[i] >= 32 && Double[i] <= 45 || Double[i] == 47 || Double[i] >= 58 && Double[i] <= 64 || Double[i] >= 91 && Double[i] <= 96 || Double[i] >= 123 && Double[i] <= 127) {
			flag = false;
			break;
		}
		else
			flag = true;
	}
	return flag;


	return false;
}

bool IsVariable (string variable)
{
	// checks if the input string is a variable name
	// return true if it can be a variable name, false otherwise

	// Variable names must start with an alphabetic letter (small or capital) or an underscore (_). 
	// After the first initial letter, variable names can contain letters, numbers and underscores.  
	// No spaces or special characters, however, are allowed.

	//TODO: complete this function
	bool flag = true;

	if (variable[0] >= 65 && variable[0] <= 90 || variable[0] >= 97 && variable[0] <= 122 || variable[0] == 95)
	{
		for (int i = 1;i < variable.length();i++) {
			if ((variable[i] >= 32 && variable[i] <= 47) || (variable[i] >= 58 && variable[i] <= 64) || (variable[i] >= 91 && variable[i] <= 96) || (variable[i] >= 123 && variable[i] <= 127))
				flag = false;
		}
	}
	else
		flag = false;
	return flag;


	return false;
}

OpType ValueOrVariable (string c)
{
	// checks if the input string is a double value or a variable name
	// chand returns enum "OpType" (the enum is declared in the .h)

	//TODO: complete this function
	OpType x;
	string z;
	if (IsValue(c))
	{
		x = VALUE_OP;
		z = "Value";
	}
	else if (IsVariable(c))
	{
		x = VARIABLE_OP;
		z = "Variable";
	}
	else
	{
		x = INVALID_OP;
		z = "Invalid";
	}
	return x;
}
