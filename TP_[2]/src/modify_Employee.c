
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "modify_Employee.h"
#include "ArrayEmployees.h"
#include "Inputs.h"




/**
 * @fn void modifyEmployeeMenu(Employee*, int, int)
 * @brief [MODIFY EMPLOYEE MENU - Allows to modificate employee information]
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @param employeeCounter int
 */
void modifyEmployeeMenu(Employee* list, int len, int employeeCounter)
{
	int idForSearch;
	int indexPositionForSearch;
	int subMenuOption;
	int keepModifying;

	if (employeeCounter > 0)
	{

		printEmployees(list, len);

		idForSearch = getIntAboveMinimum("\n\n*******************************************************************************************************************\n\n"
											  "Enter employee ID that you want to modify: \n\n"
											  "*******************************************************************************************************************\n\n",

											  "Error - reason: [Invalid ID]\n"
											  "Please enter employee ID again: \n", ID);

		indexPositionForSearch = findEmployeeById(list, len, idForSearch);

		if (indexPositionForSearch != -1)
		{
			do {
				subMenuOption = getIntInMinMaxRange("\n\nMODIFICATION MENU\n"
													"------------------------------------------------------------------------------------------------\n"
													"What do you want to modify?\n\n"
													"1. Employee Name\n"
													"2. Employee Last Name\n"
													"3. Employee Salary\n"
													"4. Employee Sector\n"
													"------------------------------------------------------------------------------------------------\n\n",

													"\n\nError - reason: [Invalid option]\n"
													"Please enter an option again.\n"
													"Modification Menu\n"
													"------------------------------------------------------------------------------------------------\n"
													"What do you want to modify?\n"
													"1. Employee Name\n"
													"2. Employee Last Name\n"
													"3. Employee Salary\n"
													"4. Employee Sector\n"
													"------------------------------------------------------------------------------------------------\n\n", 1, 4);


				switch(subMenuOption)
				{
					case 1:
						modifyName(list, len, indexPositionForSearch);
						break;

					case 2:
						modifyLastName(list, len, indexPositionForSearch);
						break;

					case 3:
						modifySalary(list, len, indexPositionForSearch);
						break;

					case 4:
						modifySector(list, len, indexPositionForSearch);
						break;
				}

				system("pause");

				keepModifying = getIntInMinMaxRange("\n\n\nDo you want to keep modifying this employee?\n"
													"------------------------------------------------------------------------------------------------\n"
													"1. YES\n"
													"2. NO, back to Main Menu\n\n\n",

													"\n\nError - reason: [Invalid option]\n"
													"Please enter an option again:\n"
													"Do you want to keep modifying this employee?\n"
													"------------------------------------------------------------------------------------------------\n"
													"1. YES\n"
													"2. NO, back to Main Menu\n\n\n", 1, 2);


			} while (keepModifying != 2);

		}
	}
	else
	{
		printf("\n------------------------------------------------------------------------------------------------\n"
				"Error. Do not allowed modifications - reason: [No employee loaded in system]\n"
				"------------------------------------------------------------------------------------------------\n\n\n\n");

		system("pause");
	}

}






/**
 * @fn void modifyName(Employee*, int, int)
 * @brief [MODIFY NAME - Allows to modificate employee's name]
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @param indexPosition int
 */
void modifyName(Employee* list, int len, int indexPosition)
{
	char newName[MAX_STRING_LENGHT];

	if (list != NULL && len > -1)
	{
		getString(newName, "Enter employee new name: ", "Error - reason: [Invalid name]. Please enter name again: ", MAX_STRING_LENGHT);
		strcpy(list[indexPosition].name, newName);
		printf("\n________________________________________________________________________________________________\n\n"
				"Employee name changed successfully!...\n"
				"________________________________________________________________________________________________\n\n\n");
	}
	else
	{
		printf("\n------------------------------------------------------------------------------------------------\n"
				"Error - reason: [Invalid length or NULL pointer...]\n\n"
				"------------------------------------------------------------------------------------------------\n\n\n");
	}
}






/**
 * @fn void modifyLastName(Employee*, int, int)
 * @brief [MODIFY LAST NAME - Allows to modificate employee's last name]
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @param indexPosition int
 */
void modifyLastName(Employee* list, int len, int indexPosition)
{
	char newLastName[MAX_STRING_LENGHT];

	if (list != NULL && len > -1)
	{
		getString(newLastName, "Enter employee new last name: ", "Error - reason: [Invalid last name]. Please enter last name again: ", MAX_STRING_LENGHT);
		strcpy(list[indexPosition].lastName, newLastName);
		printf("\n________________________________________________________________________________________________\n\n"
				"Employee last name changed successfully!...\n"
				"________________________________________________________________________________________________\n\n\n");
	}
	else
	{
		printf("\n------------------------------------------------------------------------------------------------\n"
				"Error - reason: [Invalid length or NULL pointer...]\n\n"
				"------------------------------------------------------------------------------------------------\n\n\n");
	}
}






/**
 * @fn void modifySalary(Employee*, int, int)
 * @brief [MODIFY SALARY - Allows to modificate employee's salary]
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @param indexPosition int
 */
void modifySalary(Employee* list, int len, int indexPosition)
{
	float newSalary;

	if (list != NULL && len > -1)
	{
		newSalary = getFloatInMinMaxRange("Enter employee new salary: ", "Error - reason: [Invalid salary]. Please enter salary again: ", 0, MAX_SALARY);
		list[indexPosition].salary = newSalary;
		printf("\n________________________________________________________________________________________________\n\n"
				"Employee salary changed successfully!...\n"
				"________________________________________________________________________________________________\n\n\n");
	}
	else
	{
		printf("\n------------------------------------------------------------------------------------------------\n"
				"Error - reason: [Invalid length or NULL pointer...]\n\n"
				"------------------------------------------------------------------------------------------------\n\n\n");
	}
}






/**
 * @fn void modifySector(Employee*, int, int)
 * @brief [MODIFY SECTOR - Allows to modificate employee's sector]
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @param indexPosition int
 */
void modifySector(Employee* list, int len, int indexPosition)
{
	int newSector;

	if (list != NULL && len > -1)
	{
		newSector = getIntInMinMaxRange("Enter employee new sector: ", "Error - reason: [Invalid sector]. Please enter sector again: ", 1, MAX_SECTOR);
		list[indexPosition].sector = newSector;
		printf("\n________________________________________________________________________________________________\n\n"
				"Employee sector changed successfully!...\n"
				"________________________________________________________________________________________________\n\n\n");
	}
	else
	{
		printf("\n------------------------------------------------------------------------------------------------\n"
				"Error - reason: [Invalid length or NULL pointer...]\n\n"
				"------------------------------------------------------------------------------------------------\n\n\n");
	}
}


















