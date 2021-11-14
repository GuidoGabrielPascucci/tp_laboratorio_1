#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Inputs.h"
#include "Validations.h"



/**
 * @fn int getIntInMinMaxRange(int*, char*, char*, int, int)
 * @brief [GET INT IN MIN MAX RANGE - Permite al usuario ingresar un numero entero en un rango de un numero minimo y un numero maximo]
 *
 * @param enteredNumber
 * @param message
 * @param errorMessage
 * @param min
 * @param max
 * @return Retorna [0] si algun dato es NULL / [1] si OK
 */
int getIntInMinMaxRange(int* enteredNumber, char* message, char* errorMessage, int min, int max) {
	int functionReturn = 0;
	int enterIntNumber;

	if(enteredNumber != NULL && message != NULL && errorMessage != NULL && min < max) {
		printf("%s", message);
		fflush(stdin);
		scanf("%d", &enterIntNumber);

		while(enterIntNumber < min || enterIntNumber > max) {
			printf("%s", errorMessage);
			fflush(stdin);
			scanf("%d", &enterIntNumber);
		}

		*enteredNumber = enterIntNumber;
		functionReturn = 1;
	}

	return functionReturn;
}



/**
 * @fn int getNumeroMayorQueMinimo(int*, char*, char*, int)
 * @brief [GET NUMERO MAYOR QUE MINIMO - Permite al usuario ingresar un numero entero que sea mayor a un numero minimo establecido]
 *
 * @param enteredNumber
 * @param message
 * @param errorMessage
 * @param min
 * @return Retorna [0] si algun dato es NULL / [1] si OK
 */
int getIntHigherThan(int* enteredNumber, char* message, char* errorMessage, int min) {
	int functionReturn = 0;
	int enterIntNumber;

	if(enteredNumber != NULL && message != NULL && errorMessage != NULL) {
		printf("%s", message);
		fflush(stdin);
		scanf("%d", &enterIntNumber);

		while(enterIntNumber < min) {
			printf("%s", errorMessage);
			fflush(stdin);
			scanf("%d", &enterIntNumber);
		}

		*enteredNumber = enterIntNumber;
		functionReturn = 1;
	}

	return functionReturn;
}






/**
 * @fn int getString(char*, char*, char*, int)
 * @brief [GET STRING - Permite al usuario ingresar una cadena de caracteres que no supere la cantidad maxima de caracteres establecida]
 *
 * @param string
 * @param message
 * @param errorMessage
 * @param max
 * @return Retorna [0] si algun dato es NULL / [1] si OK
 */
int getString(char* string, char* message, char* errorMessage, int max) {
	int functionReturn = 0;
	char notValidateString[200];
	int length;

	if(string != NULL && message != NULL && errorMessage != NULL) {
		printf("%s", message);
		fflush(stdin);
		scanf("%[^\n]", notValidateString);
		length = strlen(notValidateString);

		while(length > max || validateString(notValidateString, length)) {
			printf("%s", errorMessage);
			fflush(stdin);
			scanf("%[^\n]", notValidateString);
			length = strlen(notValidateString);
		}

		customizeStringForNames(notValidateString, length);
		strcpy(string, notValidateString);
		functionReturn = 1;
	}


	return functionReturn;
}



