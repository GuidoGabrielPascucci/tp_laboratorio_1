#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_



#define MAX_EMPLOYEES 15
#define MAX_STRING_LENGHT 51
#define ID 1000
#define MAX_SALARY 1000000
#define MAX_SECTOR 10
#define TRUE 1
#define FALSE 0




struct
{
 int id;
 char name[MAX_STRING_LENGHT];
 char lastName[MAX_STRING_LENGHT];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;





int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);
int findEmployeeById(Employee* list, int len, int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);



#endif




