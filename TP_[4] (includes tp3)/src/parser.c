#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

#include <string.h>
#include "Inputs.h"





/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee) {

	int retorno = 0;
	char id[11];
	char nombre[128];
	char horasTrabajadas[11];
	char sueldo[11];

	if(pFile != NULL && pArrayListEmployee != NULL) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo);

		while(!feof(pFile)) {
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo);

			if(feof(pFile)) {
				break;
			}

			Employee *pEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
			ll_add(pArrayListEmployee, pEmployee);
		}

		retorno = 1;
	}


	return retorno;
}




/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee) {

	int retorno = 0;
	Employee *pEmployee = NULL;

	if(pFile != NULL && pArrayListEmployee != NULL) {

		while(!feof(pFile)) {
			pEmployee = employee_new();
			fread(pEmployee, sizeof(Employee), 1, pFile);

			if(feof(pFile)) {
				break;
			}

			ll_add(pArrayListEmployee, pEmployee);
			pEmployee = NULL;
		}

		retorno = 1;
	}


    return retorno;
}




