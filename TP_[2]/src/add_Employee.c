
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "add_Employee.h"
#include "ArrayEmployees.h"
#include "Inputs.h"





/**
 * @fn void enterEmployeeMenu(Employee*, int, int*, int*)
 * @brief [ENTER EMPLOYEE MENU - It takes information from enterEmployeeData and it carrys to addEmployee. Plus, it asks user if want to add more employees]
 *
 * @param list Employee* Pointer to array of employees
 * @param length int Array length
 * @param employeeCounter int Pointer to employeeCounter
 * @param idCounter Pointer to idCounter
 */
void enterEmployeeMenu(Employee* list, int length, int* employeeCounter, int* idCounter)
{
	int idResult;

	char name[MAX_STRING_LENGHT];
	char lastName[MAX_STRING_LENGHT];
	float salary;
	int sector;

	int keepEnteringEmployees;


	do
	{
		if ( !enterEmployeeData(list, length, &idResult, idCounter, name, lastName, &salary, &sector) )
		{
			addEmployee(list, length, idResult, name, lastName, salary, sector);

			(*idCounter)++;
			(*employeeCounter)++;

			keepEnteringEmployees = getIntInMinMaxRange("Do you want to enter another employee?:\n"
													    "-------------------------------------------------------------------------------------------------------------------\n"
													    "1. Keep entering employees\n"
													    "0. Back to Main Menu\n\n\n\n\n",

													    "\n\nError - reason: [Invalid option]\n"
													    "Please enter an option again\n"
													    "1. Keep entering employees\n"
													    "0. Back to Main Menu\n\n\n", 0, 1);

		}
		else
		{
			break;
		}

	} while (keepEnteringEmployees);


}





/**
 * @fn int enterEmployeeData(Employee*, int, int*, int*, char*, char*, float*, int*)
 * @brief [ENTER EMPLOYEE DATA - It enters employee information in system]
 *
 * @param list Employee* Pointer to array of employees
 * @param length int Array length
 * @param id int Pointer to id
 * @param idCounter int Pointer to idCounter
 * @param name char Pointer to name
 * @param lastName char Pointer to lastName
 * @param salary float Pointer to salary
 * @param sector int Pointer to sector
 * @return Returns an INTEGER: [-1] if Error / [0] if OK
 */
int enterEmployeeData(Employee* list, int length, int* id, int* idCounter, char* name, char* lastName, float* salary, int* sector)
{
	int returnValue = -1;

	if (list != NULL && length > -1)
	{

		if (getEmptySpaceInArray(list, length) != -1)
		{

			printf("\n\n*******************************************************************************************************************\n\n"
					"Entering a new employee...\n"
					"Please fill in the fields\n\n"
					"*******************************************************************************************************************\n\n");

			*id = generateId(*idCounter);
			getString(name, "Enter name: ", "Error. Please enter name again: ", MAX_STRING_LENGHT);
			getString(lastName, "Enter last name: ", "Error. Please enter last name again: ", MAX_STRING_LENGHT);
			*salary = getFloatInMinMaxRange("Enter salary: ", "Error. Please enter salary again: ", 0, MAX_SALARY);
			*sector = getIntInMinMaxRange("Enter sector: ", "Error. Please enter sector again: ", 0, MAX_SECTOR);

			returnValue = 0;

		}
		else
		{
			printf("\n------------------------------------------------------------------------------------------------\n"
					"Error - reason: [No empty space to enter an employee...]\n"
					"------------------------------------------------------------------------------------------------\n\n\n");
		}

	}


	return returnValue;
}






/**
 * @fn int getEmptySpaceInArray(Employee*, int)
 * @brief [GET EMPTY SPACE IN ARRAY - It searchs for an available space on employee array]
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @return Returns an INDEX: [x] if OK / [-1] if array is full
 */
int getEmptySpaceInArray(Employee* list, int len)
{
	int index = -1;

	for (int i = 0; i < len; ++i)
	{
		if (list[i].isEmpty == TRUE)
		{
			index = i;
			break;
		}
	}
	return index;
}






/**
 * @fn int generateId(int)
 * @brief [GENERATE ID - it generates an ID for each employee]
 *
 * @param idCounter int
 * @return Returns an ID to identify an employee
 */
int generateId(int idCounter)
{
	int generatedId;

	if (idCounter == 0)
	{
		generatedId = ID;
	}
	else
	{
		generatedId = ID + idCounter;
	}

	return generatedId;
}


























