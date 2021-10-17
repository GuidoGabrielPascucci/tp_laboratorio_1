
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Nexo.h"
#include "Inputs.h"
#include "ArrayEmployees.h"

#include "add_Employee.h"
#include "modify_Employee.h"
#include "remove_Employee.h"
#include "inform_Employee.h"




/**
 * @fn void showMainMenu(Employee*, int)
 * @brief [SHOW MAIN MENU - It shows the main menu with all the functions that the program can do]
 *
 * @param list Employee* Pointer to array of employees
 * @param length int Array length
 */
void showMainMenu(Employee* list, int length)
{
	int idCounter = 0;
	int employeeCounter = 0;
	int option;

	do
		{
			option = getIntInMinMaxRange("\n___________________________________________________________________________________________________________________\n\n\n"
										 "\t\t\t\t\t\tMAIN MENU\n\n"
										 "___________________________________________________________________________________________________________________\n\n"
										 "Enter an option:\n"
										 "-------------------------------------------------------------------------------------------------------------------\n\n"
										 "1. ALTA\n"
										 "2. MODIFICAR\n"
										 "3. BAJA\n"
										 "4. INFORMAR\n"
										 "5. EXIT\n\n\n"
										 "___________________________________________________________________________________________________________________\n\n",

										 "\nError - reason: [Invalid Entry]. Enter an option again:\n"
										 "___________________________________________________________________________________________________________________\n\n"
										 "1. ALTA\n"
										 "2. MODIFICAR\n"
										 "3. BAJA\n"
										 "4. INFORMAR\n"
										 "5. EXIT\n\n\n", 1, 5);


			switch (option)
			{
				case 1:
					enterEmployeeMenu(list, length, &employeeCounter, &idCounter);
					break;

				case 2:
					modifyEmployeeMenu(list, length, employeeCounter);
					break;

				case 3:
					removeEmployeeMenu(list, length, &employeeCounter);
					break;

				case 4:
					informEmployeeMenu(list, length, employeeCounter);
					break;

				case 5:
					// Exit Program
					break;
			}


		} while (option != 5);

}




/**
 * @fn void showEmployee(Employee*)
 * @brief [SHOW EMPLOYEE - It shows an employee with all his information]
 *
 * @param list Employee* Pointer to array of employees
 */
void showEmployee(Employee* list)
{
	printf("%-15d %-31s %-30s %-20.2f %-10d\n", (*list).id, (*list).name, (*list).lastName, (*list).salary, (*list).sector);
}























