
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "remove_Employee.h"
#include "ArrayEmployees.h"
#include "Inputs.h"



/**
 * @fn void removeEmployeeMenu(Employee*, int, int*)
 * @brief [REMOVE EMPLOYEE NAME - Allows to remove an employee from the list]
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @param employeeCounter int Pointer to employeeCounter
 */
void removeEmployeeMenu(Employee* list, int len, int* employeeCounter)
{
	int idForSearch;
	int indexPositionForSearch;
	int keepRemovingEmployees;


	if (list != NULL && len > -1)
	{
		do
		{
			if (*employeeCounter > 0)
			{
				printEmployees(list, len);

				idForSearch = getIntAboveMinimum("*******************************************************************************************************************\n\n"
											     "Remove Employee\n"
											     "Enter employee ID that you want to remove: \n\n"
											     "*******************************************************************************************************************\n\n\n",

											     "*******************************************************************************************************************\n\n"
											     "! Error - reason: [Invalid ID]\n"
											     "Please enter employee ID again: \n\n"
											     "*******************************************************************************************************************\n\n\n", ID);


				indexPositionForSearch = findEmployeeById(list, len, idForSearch);

				if ( (indexPositionForSearch != -1) && (!removeEmployee(list, len, idForSearch)) && (verifyRemoveEmployee(list, indexPositionForSearch)) )
				{
					(*employeeCounter)--;
				}


				keepRemovingEmployees = getIntInMinMaxRange("\n\n\n\n------------------------------------------------------------------------------------------------\n"
																 "Do you want to keep removing employees?\n"
																 "------------------------------------------------------------------------------------------------\n"
																 "1. Remove another employee\n"
																 "2. Back to Main Menu\n\n\n\n",

																 "! Error - reason: [Invalid option]\n"
																 "Please enter an option again\n"
																 "------------------------------------------------------------------------------------------------\n"
																 "Do you want to keep removing employees??"
																 "------------------------------------------------------------------------------------------------\n\n"
																 "1. Remove another employee\n"
																 "2. Back to Main Menu\n\n\n\n", 1, 2);
			}
			else
			{
				printf("\n------------------------------------------------------------------------------------------------\n"
						"Error. Do not allowed to remove employees - reason: [No employee loaded in system]\n"
						"------------------------------------------------------------------------------------------------\n\n\n\n");

				system("pause");
				break;
			}

		} while (keepRemovingEmployees != 2);

	}
	else
	{
		printf("\n------------------------------------------------------------------------------------------------\n"
			   "Error - reason: [Invalid length or NULL pointer]\n\n\n"
			   "------------------------------------------------------------------------------------------------\n\n\n\n");

		system("pause");
	}

}






/**
 * @fn int verifyRemoveEmployee(Employee*, int)
 * @brief [VERIFY REMOVE EMPLOYEES - Security check to confirm the removing of the employee from the list]
 *
 * @param list Employee* Pointer to array of employees
 * @param index int
 * @return Returns [0] if Undo Changes / [1] if confirm to remove employee
 */
int verifyRemoveEmployee(Employee* list, int index)
{
	int verification;
	verification = getIntInMinMaxRange("\n\n*****************************************************************************************************************\n\n"
										"Security Check\n\n"
										"*****************************************************************************************************************\n\n"
										"Do you confirm that you want to remove this employee from the list?\n"
										"1. Remove Employee\n"
										"0. Undo changes\n\n",

										"\n\n\nError ! - reason: [Invalid option]\n"
										"Please enter an option again...\n\n"
										"*****************************************************************************************************************\n"
										"Security Check\n"
										"*****************************************************************************************************************\n"
										"Do you confirm that you want to remove this employee from the list?\n\n"
										"1. Remove Employee\n"
										"0. Undo changes\n\n", 0, 1);

	if (verification)
	{
		printf("\n\n___________________________________________________________________________________________________________________\n\n"
				"Employee removed successfully!...\n"
				"___________________________________________________________________________________________________________________\n\n\n");
	}
	else
	{
		list[index].isEmpty = FALSE;
		printf("\n\n___________________________________________________________________________________________________________________\n\n"
				"Changes have been restored.\n"
				"___________________________________________________________________________________________________________________\n\n\n");
	}

	system("pause");

	return verification;
}



















