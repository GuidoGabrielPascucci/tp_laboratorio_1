
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Inputs.h"
#include "Validations.h"




/**
 * @fn int getIntInMinMaxRange(char*, char*, int, int)
 * @brief [GET INT IN MIN MAX RANGE - Allows user to enter an integer in a range between minimum and maximum]
 *
 * @param message char Pointer to message
 * @param errorMessage char Pointer to errorMessage
 * @param min int
 * @param max int
 * @return Returns the INTEGER entered by user after validate it
 */
int getIntInMinMaxRange(char* message, char* errorMessage, int min, int max)
{
	int enterIntNumber;

	if (message != NULL && errorMessage != NULL && min < max)
	{
		printf("%s", message);
		fflush(stdin);
		scanf("%d", &enterIntNumber);

		while ( (validateInteger(enterIntNumber)) || (enterIntNumber < min || enterIntNumber > max) )
		{
			printf("%s", errorMessage);
			fflush(stdin);
			scanf("%d", &enterIntNumber);
		}

	}

	return enterIntNumber;
}






/**
 * @fn int getIntAboveMinimum(char*, char*, int)
 * @brief [GET INT ABOVE MINIMUM - Allows user to enter an integer higher than the minimum]
 *
 * @param message char Pointer to message
 * @param errorMessage char Pointer to errorMessage
 * @param min int
 * @return Returns the INTEGER entered by user after validate it
 */
int getIntAboveMinimum(char* message, char* errorMessage, int min)
{
	int enterIntNumber;

	printf("%s", message);
	fflush(stdin);
	scanf("%d", &enterIntNumber);

	while ( (validateInteger(enterIntNumber)) ||enterIntNumber < min) {
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%d", &enterIntNumber);
	}

	return enterIntNumber;
}







/**
 * @fn float getFloatInMinMaxRange(char*, char*, int, int)
 * @brief [GET FLOAT IN MIN MAX RANGE - Allows user to enter a float in a range between minimum and maximum]
 *
 * @param message char Pointer to message
 * @param errorMessage char Pointer to errorMessage
 * @param min int
 * @param max int
 * @return
 */
float getFloatInMinMaxRange(char* message, char* errorMessage, int min, int max) {
	float enterFloatNumber;

	printf("%s", message);
	fflush(stdin);
	scanf("%f", &enterFloatNumber);

	while (enterFloatNumber < min || enterFloatNumber > max) {
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%f", &enterFloatNumber);
	}

	return enterFloatNumber;
}







/**
 * @fn void getString(char*, char*, char*, int)
 * @brief [GET STRING - Allows user to enter a string under the maximum characters established]
 *
 * @param string char Pointer to string
 * @param message char Pointer to message
 * @param errorMessage char Pointer to errorMessage
 * @param max int
 */
void getString(char* string, char* message, char* errorMessage, int max)
{
	char notValidateString[200];
	int length;

	printf("%s", message);
	fflush(stdin);
	scanf("%[^\n]", notValidateString);
	length = strlen(notValidateString);

	while (length > max || validateString(notValidateString, length) )
	{
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%[^\n]", notValidateString);
		length = strlen(notValidateString);
	}

	customizeStringForNames(notValidateString, length);
	strcpy(string, notValidateString);
}














