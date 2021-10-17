#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployees.h"
#include "Nexo.h"
#include "Inputs.h"
#include "add_Employee.h"
#include "modify_Employee.h"
#include "remove_Employee.h"
#include "inform_Employee.h"




/**
 * @fn int initEmployees(Employee*, int)
 * @brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array.
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initEmployees(Employee* list, int len)
{
	int functionReturn = -1;

	if (list != NULL || len > -1)
	{
		for (int i = 0; i < len; ++i)
		{
			list[i].isEmpty = TRUE;
		}

		functionReturn = 0;
	}
	else
	{
		printf("\n------------------------------------------------------------------------------------------------\n"
				"Invalid length or NULL pointer...\n"
				"------------------------------------------------------------------------------------------------\n\n\n");
	}

	return functionReturn;
}


/**
 * @fn int addEmployee(Employee*, int, int, char[], char[], float, int)
 * @brief add in a existing list of employees the values received as parameters in the first empty position.
 *
 * @param list employee*
 * @param len int
 * @param id int
 * @param name[] char
 * @param lastName[] char
 * @param salary float
 * @param sector int
 * @return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int returnValue = -1;
	int index;

	if (list != NULL && len > -1)
	{
		index = getEmptySpaceInArray(list, len);

		list[index].id = id;
		strcpy(list[index].name, name);
		strcpy(list[index].lastName, lastName);
		list[index].salary = salary;
		list[index].sector = sector;
		list[index].isEmpty = FALSE;

		printf("\n___________________________________________________________________________________________________________________\n\n"
				"Employee %s %s, was added successfully!\n"
				"___________________________________________________________________________________________________________________\n\n\n", list[index].name, list[index].lastName);
		returnValue = 0;
	}
	else
	{
		printf("\n------------------------------------------------------------------------------------------------\n"
				"[Invalid length or NULL pointer or without free space]\n"
				"------------------------------------------------------------------------------------------------\n\n\n");
	}

	return returnValue;
}


/**
 * @fn int findEmployeeById(Employee*, int, int)
 * @brief find an Employee by Id and returns the index position in array.
 *
 * @param list Employee*
 * @param len int
 * @param id int
 * @return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 */
int findEmployeeById(Employee* list, int len, int id)
{
	int employeeIndexPosition = -1;

	if (list != NULL)
	{
		for (int i = 0; i < len; ++i)
		{
			if (id == list[i].id)
			{
				employeeIndexPosition = i;
				break;
			}
		}

		if (employeeIndexPosition == -1)
		{
			printf("\n------------------------------------------------------------------------------------------------\n"
					"Error - Reason: [Employee not found]\n"
					"------------------------------------------------------------------------------------------------\n\n\n");
		}

	}
	else
	{
		printf("\n------------------------------------------------------------------------------------------------\n"
				"Error - Reason: [Invalid length or NULL pointer received]\n"
				"------------------------------------------------------------------------------------------------\n\n\n");
	}

	return employeeIndexPosition;
}




/**
 * @fn int removeEmployee(Employee*, int, int)
 * @brief Remove an Employee by Id (put isEmpty Flag in 1)
 *
 * @param list Employee*
 * @param len int
 * @param id int
 * @return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 */
int removeEmployee(Employee* list, int len, int id)
{
	int functionValue = -1;

	if (list != NULL && len > -1)
	{
		for (int i = 0; i < len; ++i)
		{
			if (id == list[i].id)
			{
				list[i].isEmpty = TRUE;
				functionValue = 0;
				break;
			}
		}

	}
	else
	{
		printf("\n------------------------------------------------------------------------------------------------\n"
				"Error - motivo: [Invalid length or NULL pointer]\n"
				"------------------------------------------------------------------------------------------------\n\n\n");
	}

	return functionValue;
}


/**
 * @fn int sortEmployees(Employee*, int, int)
 * @brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 *
 * @param list Employee*
 * @param len int
 * @param order int [1] indicate UP - [0] indicate DOWN
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortEmployees(Employee* list, int len, int order)
{
	int functionValue = -1;

	if (list != NULL && len > -1)
	{
		switch(order)
		{
			case 0:

				sortDown(list, len);
				functionValue = 0;

				break;

			case 1:

				sortUp(list, len);
				functionValue = 0;

				break;
		}
	}
	else
	{
		printf("\nError [Invalid length or NULL pointer]\n");
	}


	return functionValue;
}




/**
 * @fn int printEmployees(Employee*, int)
 * @brief print the content of employees array
 *
 * @param list Employee*
 * @param length int
 * @return int
 */
int printEmployees(Employee* list, int length)
{
	int functionValue = -1;

	if (list != NULL && length > -1)
	{
			printf("\n\n\n___________________________________________________________________________________________________________________\n\n\n"
					"\t\t\t\t\t\tEmployee List\n\n"
					"___________________________________________________________________________________________________________________\n\n"
					"%-15s %-31s %-30s %-20s %-10s\n", "ID", "Name", "Last Name", "Salary", "Sector\n"
					"___________________________________________________________________________________________________________________\n");


			for (int i = 0; i < length; ++i)
			{
				if (list[i].isEmpty == FALSE)
				{
					showEmployee(&list[i]);
				}
			}

		printf("\n\n\n\n\n");
		functionValue = 0;
	}
	else
	{
		printf("\n------------------------------------------------------------------------------------------------\n"
				"No se pudo mostrar el listado [Datos inválidos]\n"
				"------------------------------------------------------------------------------------------------\n\n\n");
	}

	return functionValue;
}









