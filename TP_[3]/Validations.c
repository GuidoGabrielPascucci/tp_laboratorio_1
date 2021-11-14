#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Validations.h"



/**
 * @fn int validateString(char*, int)
 * @brief [VALIDATE STRING - Validates that the string is free of numbers or symbols. It only allows alphabetic letters (a - z) or spaces (between two letters)]
 *
 * @param string char Pointer to string
 * @param length int
 * @return Returns an INTEGER: [-1] if error / [0] if OK
 */
int validateString(char* string, int length)
{
	int functionValue = 0;
	int i;


	for (i = 0; i < length; ++i)
	{
		if ( (isdigit(string[i])) || string[i] < 32 || (string[i] > 32 && string[i] < 65) || (string[i] > 90 && string[i] < 97) || string[i] > 122 )
		{
			functionValue = -1;
			break;
		}
	}


	for (i = 0; i < length; ++i)
	{
		if (string[i] == 32 && string[i+1] == 32)
		{
			functionValue = -1;
			break;
		}
	}


	return functionValue;
}






/**
 * @fn void customizeStringForNames(char*, int)
 * @brief [CUSTOMIZE STRING FOR NAMES - Modifies the string]
 *
 * @param string char Pointer to string
 * @param length int
 */
void customizeStringForNames(char* string, int length)
{
	int i;

	for (i = 0; i < length; ++i)
	{
		string[i] = tolower(string[i]);
	}


	for (i = 0; i < length; ++i)
	{
		if (i == 0)
		{
			string[i] = toupper(string[i]);
		}
		else
		{
			if (string[i] == 32)
			{
				string[i+1] = toupper(string[i+1]);
			}
		}
	}

}















