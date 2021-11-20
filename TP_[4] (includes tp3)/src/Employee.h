#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this, int id);
int employee_getId(Employee* this, int* id);

int employee_setNombre(Employee* this, char* nombre);
int employee_getNombre(Employee* this, char* nombre);

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);

int employee_setSueldo(Employee* this, int sueldo);
int employee_getSueldo(Employee* this, int* sueldo);



int cargarDatosDeEmpleado(LinkedList* pArrayListEmployee, Employee *pEmployee);
int editarEmpleado(Employee* pEmployee);
int removerEmpleado(Employee* pEmployee, LinkedList* pArrayListEmployee, int index);
int sortByID(Employee* pEmployeeA, Employee* pEmployeeB);
int sortByName(Employee* pEmployeeA, Employee* pEmployeeB);
int sortByHours(Employee* pEmployeeA, Employee* pEmployeeB);
int sortBySalary(Employee* pEmployeeA, Employee* pEmployeeB);


#endif // employee_H_INCLUDED
