/*
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
		TP_2_LABORATORY
		AUTHOR: 	PASCUCCI, GUIDO GABRIEL
		DIV:		1° D
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#include "ArrayEmployees.h"
#include "Nexo.h"



int main(void)
{
	setbuf(stdout, NULL);

	printf("\n\n\t\t\t\t\t« UTN CORPORATION® » WELCOME!\n\n");

	Employee arrayEmployees[MAX_EMPLOYEES];

	initEmployees(arrayEmployees, MAX_EMPLOYEES);

	showMainMenu(arrayEmployees, MAX_EMPLOYEES);

	printf("\n\n\n\n\n"
			"Thank you for being there! Bye!\n"
			"Exit Program\n\n");


	return EXIT_SUCCESS;
}




