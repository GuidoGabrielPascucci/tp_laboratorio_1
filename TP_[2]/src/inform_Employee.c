
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inform_Employee.h"
#include "ArrayEmployees.h"
#include "Inputs.h"





/**
 * @fn void informEmployeeMenu(Employee*, int, int)
 * @brief [INFORM EMPLOYEE MENU - Menu with option to sort employees or deploy salarys information]
 *
 * @param list Employee* Pointer to array of employees
 * @param length int Array length
 * @param employeeCounter int
 */
void informEmployeeMenu(Employee* list, int length, int employeeCounter)
{
	int optionToChoose;

	if (list != NULL && length > -1)
	{
		if (employeeCounter > 0)
		{

			optionToChoose = getIntInMinMaxRange("\n\nINFORM MENU\n"
												 "-------------------------------------------------------------------------------------------------------------------\n"
												 "1. Sort Employees (by Last Name & Sector)\n"
												 "2. Salarys Information\n\n\n",

												 "Error - reason: [Invalid option]\n"
												 "Please enter an option again:\n"
												 "-------------------------------------------------------------------------------------------------------------------\n"
												 "1. Sort Employees (by Last Name & Sector)\n"
												 "2. Salarys Information\n\n\n", 1, 2);


			switch(optionToChoose)
			{
				case 1:
					sortMenu(list, length);
					break;

				case 2:
					showSalarysInformation(list, length, employeeCounter);
					break;
			}


		}
		else
		{
			printf("\n-------------------------------------------------------------------------------------------------------------------\n"
					"Error - reason: [No employee loaded in system]\n"
					"-------------------------------------------------------------------------------------------------------------------\n\n\n\n");
		}
	}
	else
	{
		printf("\n\n\n-------------------------------------------------------------------------------------------------------------------\n"
				"\nError [Invalid length or NULL pointer]\n"
				"-------------------------------------------------------------------------------------------------------------------\n\n\n\n");
	}

	system("pause");
}






/**
 * @fn void sortMenu(Employee*, int)
 * @brief [SORT MENU - Menu with option to sort employees by down or up order]
 *
 * @param list Employee* Pointer to array of employees
 * @param length int Array length
 */
void sortMenu(Employee* list, int length)
{
	int order;

	order = getIntInMinMaxRange("\nEnter order:\n"
								"-------------------------------------------------------------------------------------------------------------------\n"
								"0. DOWN\n"
								"1. UP\n\n",

								"\nError - reason: [Invalid order]\n"
								"Please enter order again:\n"
								"0. DOWN\n"
								"1. UP\n\n", 0, 1);

	if ( !sortEmployees(list, length, order) )
	{
		printEmployees(list, length);
	}

}







/**
 * @fn void sortDown(Employee*, int)
 * @brief [SORT DOWN - Sort the employee list first by last name and then by sector, in down order]
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 */
void sortDown(Employee* list, int len)
{
	int auxId;
	char auxName[MAX_STRING_LENGHT];
	char auxLastName[MAX_STRING_LENGHT];
	float auxSalary;
	int auxSector;

	int flagSwap;
	int nuevoLimite = len - 1;

	do
	{
		flagSwap = 0;

		for (int i = 0; i < nuevoLimite; ++i)
		{
			if ( (list[i].isEmpty == FALSE && list[i+1].isEmpty == FALSE) && (stricmp(list[i].lastName, list[i+1].lastName) == -1) )
			{
				// SWAP ID:
				auxId = list[i].id;
				list[i].id = list[i+1].id;
				list[i+1].id = auxId;

				// SWAP Name:
				strcpy(auxName, list[i].name);
				strcpy(list[i].name, list[i+1].name);
				strcpy(list[i+1].name, auxName);

				// SWAP Last Name:
				strcpy(auxLastName, list[i].lastName);
				strcpy(list[i].lastName, list[i+1].lastName);
				strcpy(list[i+1].lastName, auxLastName);

				// SWAP Salary:
				auxSalary = list[i].salary;
				list[i].salary = list[i+1].salary;
				list[i+1].salary = auxSalary;

				// SWAP Sector:
				auxSector = list[i].sector;
				list[i].sector = list[i+1].sector;
				list[i+1].sector = auxSector;

				flagSwap = 1;
			}
			else
			{
				if ( (list[i].isEmpty == FALSE && list[i+1].isEmpty == FALSE) && (stricmp(list[i].lastName, list[i+1].lastName) == 0) && (list[i].sector < list[i+1].sector) )
				{
					// SWAP ID:
					auxId = list[i].id;
					list[i].id = list[i+1].id;
					list[i+1].id = auxId;

					// SWAP Name:
					strcpy(auxName, list[i].name);
					strcpy(list[i].name, list[i+1].name);
					strcpy(list[i+1].name, auxName);

					// SWAP Salary:
					auxSalary = list[i].salary;
					list[i].salary = list[i+1].salary;
					list[i+1].salary = auxSalary;

					// SWAP Sector:
					auxSector = list[i].sector;
					list[i].sector = list[i+1].sector;
					list[i+1].sector = auxSector;

					flagSwap = 1;
				}
			}
		}

		nuevoLimite--;


	} while(flagSwap);

}





/**
 * @fn void sortUp(Employee*, int)
 * @brief [SORT UP - Sort the employee list first by last name and then by sector, in up order]
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 */
void sortUp(Employee* list, int len)
{
	int auxId;
	char auxName[MAX_STRING_LENGHT];
	char auxLastName[MAX_STRING_LENGHT];
	float auxSalary;
	int auxSector;

	int flagSwap;
	int nuevoLimite = len - 1;


	do
	{
		flagSwap = 0;

		for (int i = 0; i < nuevoLimite; ++i)
		{
			if ( (list[i].isEmpty == FALSE && list[i+1].isEmpty == FALSE) && (stricmp(list[i].lastName, list[i+1].lastName) == 1) )
			{
				// SWAP ID:
				auxId = list[i].id;
				list[i].id = list[i+1].id;
				list[i+1].id = auxId;

				// SWAP Name:
				strcpy(auxName, list[i].name);
				strcpy(list[i].name, list[i+1].name);
				strcpy(list[i+1].name, auxName);

				// SWAP Last Name:
				strcpy(auxLastName, list[i].lastName);
				strcpy(list[i].lastName, list[i+1].lastName);
				strcpy(list[i+1].lastName, auxLastName);

				// SWAP Salary:
				auxSalary = list[i].salary;
				list[i].salary = list[i+1].salary;
				list[i+1].salary = auxSalary;

				// SWAP Sector:
				auxSector = list[i].sector;
				list[i].sector = list[i+1].sector;
				list[i+1].sector = auxSector;

				flagSwap = 1;
			}
			else
			{
				if ( (list[i].isEmpty == FALSE && list[i+1].isEmpty == FALSE) &&  (stricmp(list[i].lastName, list[i+1].lastName) == 0) && (list[i].sector > list[i+1].sector) )
				{
					// SWAP ID:
					auxId = list[i].id;
					list[i].id = list[i+1].id;
					list[i+1].id = auxId;

					// SWAP Name:
					strcpy(auxName, list[i].name);
					strcpy(list[i].name, list[i+1].name);
					strcpy(list[i+1].name, auxName);

					// SWAP Salary:
					auxSalary = list[i].salary;
					list[i].salary = list[i+1].salary;
					list[i+1].salary = auxSalary;

					// SWAP Sector:
					auxSector = list[i].sector;
					list[i].sector = list[i+1].sector;
					list[i+1].sector = auxSector;

					flagSwap = 1;
				}
			}
		}

		nuevoLimite--;

	} while(flagSwap);

}




/**
 * @fn void showSalarysInformation(Employee*, int, int)
 * @brief [SHOW SALARYS INFORMATION - Shows information about employees salarys]
 *
 * @param list Employee* Pointer to array of employees
 * @param length int Array length
 * @param counterEmployee int
 */
void showSalarysInformation(Employee* list, int length, int counterEmployee)
{
	float totalSalary = 0;
	float averageSalary;
	int counterAboveAverage = 0;

	if (list != NULL && length > -1)
	{
		for (int i = 0; i < length; ++i)
		{
			if (list[i].isEmpty == FALSE)
			{
				totalSalary = totalSalary + list[i].salary;
			}
		}

		averageSalary = totalSalary / (float)counterEmployee;


		for (int i = 0; i < length; ++i)
		{
			if ( (list[i].isEmpty == FALSE) && (list[i].salary > averageSalary) )
			{
				counterAboveAverage++;
			}
		}



		printf("\n\n\n===================================================================================================================\n"
				"SALARYS INFORMATION\n"
				"===================================================================================================================\n"
				"%-20s %-20s %-20s\n", "Total Salary", "Average", "Above AVG Employees\n"
				"===================================================================================================================\n");


		printf("%-20.2f %-20.2f %-20d\n\n\n\n\n", totalSalary, averageSalary, counterAboveAverage);


	}
	else
	{
		printf("\n\n\n-------------------------------------------------------------------------------------------------------------------\n"
				"\nError [Invalid length or NULL pointer]\n"
				"-------------------------------------------------------------------------------------------------------------------\n\n\n\n");
	}

}













