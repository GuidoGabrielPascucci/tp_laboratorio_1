
#ifndef ADD_EMPLOYEE_H_
#define ADD_EMPLOYEE_H_


#include "ArrayEmployees.h"



void enterEmployeeMenu(Employee* list, int length, int* employeeCounter, int* idCounter);

//int enterEmployeeData(Employee* list, int length, int* id, int idCounter, char* name, char* lastName, float* salary, int* sector);

int enterEmployeeData(Employee* list, int length, int* id, int* idCounter, char* name, char* lastName, float* salary, int* sector);

int getEmptySpaceInArray(Employee* list, int len);
int generateId(int idCounter);





#endif
