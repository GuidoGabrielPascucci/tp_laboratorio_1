#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "Inputs.h"
#include "Controller.h"



/**
 * @fn Employee employee_new*()
 * @brief reserva espacio en memoria y lo asigna a un puntero tipo struct
 *
 * @return un puntero a struct
 */
Employee* employee_new() {

	Employee *pEmployee = NULL;
	pEmployee = (Employee*) malloc(sizeof(Employee));

	return pEmployee;
}



/**
 * @fn Employee employee_newParametros*(char*, char*, char*, char*)
 * @brief ademas de reservar espacio en memoria para un puntero de tipo struct, guarda datos en los campos de la misma
 *
 * @param idStr
 * @param nombreStr
 * @param horasTrabajadasStr
 * @param sueldoStr
 * @return un puntero a struct
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr) {

	Employee *pEmployee = NULL;
	pEmployee = employee_new();

	if(pEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL) {
		employee_setId(pEmployee, atoi(idStr));
		employee_setNombre(pEmployee, nombreStr);
		employee_setHorasTrabajadas(pEmployee, atoi(horasTrabajadasStr));
		employee_setSueldo(pEmployee, atoi(sueldoStr));
	}

	return pEmployee;
}


/**
 * @fn void employee_delete(Employee*)
 * @brief libera memoria y fija el puntero a struct en NULL - borra el empleado de la lista
 *
 * @param this
 */
void employee_delete(Employee* this) {

	if(this != NULL) {
		free(this);
		this = NULL;
	}

}


/**
 * @fn int employee_setId(Employee*, int)
 * @brief guarda en la struct un dato de tipo ID
 *
 * @param this
 * @param id
 * @return [0] si el puntero es NULL / [1] si OK
 */
int employee_setId(Employee* this, int id) {

	int retorno = 0;

	if(this != NULL) {
		this->id = id;
		retorno = 1;
	}

	return retorno;
}


/**
 * @fn int employee_getId(Employee*, int*)
 * @brief trae un elemento de la struct de tipo ID
 *
 * @param this
 * @param id
 * @return [0] si el puntero es NULL / [1] si OK
 */
int employee_getId(Employee* this, int* id) {

	int retorno = 0;
	if(this != NULL) {
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}


/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief guarda en la struct un dato de tipo nombre
 *
 * @param this
 * @param nombre
 * @return [0] si el puntero es NULL / [1] si OK
 */
int employee_setNombre(Employee* this, char* nombre) {

	int retorno = 0;

	if(this != NULL) {
		strcpy(this->nombre, nombre);
		retorno = 1;
	}

	return retorno;
}


/**
 * @fn int employee_getNombre(Employee*, char*)
 * @brief trae un elemento de la struct de tipo nombre
 *
 * @param this
 * @param nombre
 * @return [0] si el puntero es NULL / [1] si OK
 */
int employee_getNombre(Employee* this, char* nombre) {

	int retorno = 0;
	if(this != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 1;
	}

	return retorno;
}



/**
 * @fn int employee_setHorasTrabajadas(Employee*, int)
 * @brief guarda en la struct un dato de tipo horas trabajadas
 *
 * @param this
 * @param horasTrabajadas
 * @return [0] si el puntero es NULL / [1] si OK
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas) {

	int retorno = 0;

	if(this != NULL) {
		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}

	return retorno;
}


/**
 * @fn int employee_getHorasTrabajadas(Employee*, int*)
 * @brief trae un elemento de la struct de tipo horas trabajadas
 *
 * @param this
 * @param horasTrabajadas
 * @return [0] si el puntero es NULL / [1] si OK
 */
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas) {

	int retorno = 0;
	if(this != NULL) {
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}

	return retorno;
}


/**
 * @fn int employee_setSueldo(Employee*, int)
 * @brief guarda en la struct un dato de tipo sueldo
 *
 * @param this
 * @param sueldo
 * @return [0] si el puntero es NULL / [1] si OK
 */
int employee_setSueldo(Employee* this, int sueldo) {

	int retorno = 0;

	if(this != NULL) {
		this->sueldo = sueldo;
		retorno = 1;
	}

	return retorno;
}


/**
 * @fn int employee_getSueldo(Employee*, int*)
 * @brief trae un elemento de la struct de tipo sueldo
 *
 * @param this
 * @param sueldo
 * @return [0] si el puntero es NULL / [1] si OK
 */
int employee_getSueldo(Employee* this, int* sueldo) {

	int retorno = 0;
	if(this != NULL) {
		*sueldo = this->sueldo;
		retorno = 1;
	}

	return retorno;
}




/**
 * @fn int cargarDatosDeEmpleado(LinkedList*, Employee*)
 * @brief carga todos los datos de los empleados a la lista
 *
 * @param pArrayListEmployee
 * @param pEmployee
 * @return [0] si el puntero o la lista es NULL / [1] si OK
 */
int cargarDatosDeEmpleado(LinkedList* pArrayListEmployee, Employee *pEmployee) {

	int retorno = 0;

	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;


	if(pArrayListEmployee != NULL && pEmployee != NULL) {

		int ultimoIndexIngresado = ll_len(pArrayListEmployee);
		id = ultimoIndexIngresado + 1;

		getString(nombre, "\n\n\n-------------------------------------------------------------------------------------------------------------------\n"
						  "Ingrese nombre: ", "ERROR <<nombre invalido>> Por favor reingrese nombre: ", 128);


		getIntInMinMaxRange(&horasTrabajadas, "-------------------------------------------------------------------------------------------------------------------\n"
											  "Ingrese total de horas trabajadas: ", "ERROR <<entrada invalida>> Por favor reingrese las horas trabajadas:", 0, 100000);


		getIntInMinMaxRange(&sueldo, "-------------------------------------------------------------------------------------------------------------------\n"
									 "Ingrese sueldo: ", "ERROR <<numero invalido>> Por favor reingrese sueldo: ", 1, 1000000);


		printf("-------------------------------------------------------------------------------------------------------------------\n");

		employee_setId(pEmployee, id);
		employee_setNombre(pEmployee, nombre);
		employee_setHorasTrabajadas(pEmployee, horasTrabajadas);
		employee_setSueldo(pEmployee, sueldo);

		retorno = 1;
	}


	return retorno;
}






/**
 * @fn int editarEmpleado(Employee*)
 * @brief edita los datos de los empleados cargados en el sistema
 *
 * @param pEmployee
 * @return la opcion seleccionada por el usuario
 */
int editarEmpleado(Employee* pEmployee) {

	int retorno;
	int option;

	char nombre[128];
	int horasTrabajadas;
	int sueldo;


	getIntInMinMaxRange(&option, "\n\n\n-------------------------------------------------------------------------------------------------------------------\n"
								 "Menu Editar Empleado\n"
								 "-------------------------------------------------------------------------------------------------------------------\n"
								 "1. Modificar Nombre\n"
								 "2. Modificar Horas Trabajadas\n"
								 "3. Modificar Sueldo\n\n"
								 "4. Volver a la seleccion de empleado\n"
								 "5. Volver al menu principal\n"
								 "-------------------------------------------------------------------------------------------------------------------\n\n\n"
								 "Selecciona la modificacion que desees realizar: ",


								 "\n\n\nERROR! <<La opcion es invalida>>\n"
								 "-------------------------------------------------------------------------------------------------------------------\n"
								 "Menu Editar Empleado\n"
								 "-------------------------------------------------------------------------------------------------------------------\n"
								 "1. Modificar Nombre\n"
								 "2. Modificar Horas Trabajadas\n"
								 "3. Modificar Sueldo\n\n"
								 "4. Volver a la seleccion de empleado\n"
								 "5. Volver al menu principal\n"
								 "-------------------------------------------------------------------------------------------------------------------\n\n\n"
								 "Vuelve a seleccionar la modificacion que desees realizar: ", 1, 5);


		switch(option) {
			case 1:
				getString(nombre, "\n\n-------------------------------------------------------------------------------------------------------------------\n"
								  "Ingrese nombre: ", "ERROR <<nombre invalido>> Por favor reingrese nombre: ", 128);

				employee_setNombre(pEmployee, nombre);
				retorno = 0;
				break;

			case 2:
				getIntInMinMaxRange(&horasTrabajadas, "\n\n-------------------------------------------------------------------------------------------------------------------\n"
													  "Ingrese total de horas trabajadas: ", "ERROR <<entrada invalida>> Por favor reingrese las horas trabajadas:", 0, 100000);

				employee_setHorasTrabajadas(pEmployee, horasTrabajadas);
				retorno = 0;
				break;

			case 3:
				getIntInMinMaxRange(&sueldo, "\n\n-------------------------------------------------------------------------------------------------------------------\n"
											 "Ingrese sueldo: ", "ERROR <<numero invalido>> Por favor reingrese sueldo: ", 1, 1000000);

				employee_setSueldo(pEmployee, sueldo);
				retorno = 0;
				break;

			case 4:
				retorno = 2;
				break;

			case 5:
				retorno = 3;
				break;
		}


	return retorno;
}






/**
 * @fn int removerEmpleado(Employee*, LinkedList*, int)
 * @brief remueve el empleado del sistema
 *
 * @param pEmployee
 * @param pArrayListEmployee
 * @param index
 * @return la opcion seleccionada por el usuario
 */
int removerEmpleado(Employee* pEmployee, LinkedList* pArrayListEmployee, int index) {

	int retorno;
	int option;


	getIntInMinMaxRange(&option, "\n\n\n-------------------------------------------------------------------------------------------------------------------\n"
								 "Menu Remover Empleado\n"
								 "-------------------------------------------------------------------------------------------------------------------\n"
								 "1. Remover Empleado de la lista\n\n"
								 "2. Volver a la seleccion de empleado\n"
								 "3. Volver al menu principal\n"
								 "-------------------------------------------------------------------------------------------------------------------\n\n\n"
								 "Selecciona la opcion que desees realizar: ",


								 "\n\n\nERROR! <<La opcion ingresada no es valida>>\n"
								 "-------------------------------------------------------------------------------------------------------------------\n"
								 "Menu Remover Empleado\n"
								 "-------------------------------------------------------------------------------------------------------------------\n"
								 "1. Remover Empleado de la lista\n\n"
								 "2. Volver a la seleccion de empleado\n"
								 "3. Volver al menu principal\n"
								 "-------------------------------------------------------------------------------------------------------------------\n\n\n"
								 "Selecciona nuevamente la opcion que desees realizar: ", 1, 3);


	switch(option) {
		case 1:
			if(confirmarRemoverEmpleado()) {
				employee_delete(pEmployee);
				ll_remove(pArrayListEmployee, index);
			retorno = 0;
			}
			else {
				retorno = 1;
			}
			break;

		case 2:
			retorno = 2;
			break;

		case 3:
			retorno = 3;
			break;
	}


	return retorno;
}






/**
 * @fn int sortByID(Employee*, Employee*)
 * @brief ordena la lista segun ID
 *
 * @param pEmployeeA
 * @param pEmployeeB
 * @return retorna [-1] / [1] segun tamanio
 */
int sortByID(Employee* pEmployeeA, Employee* pEmployeeB) {

	int employeeA;
	int employeeB;
	int retorno;

	employee_getId(pEmployeeA, &employeeA);
	employee_getId(pEmployeeB, &employeeB);

	if(employeeA > employeeB) {
		retorno = 1;
	}
	else if (employeeA < employeeB) {
		retorno = -1;
	}

	return retorno;
}



/**
 * @fn int sortByName(Employee*, Employee*)
 * @brief ordena la lista segun nombre
 *
 * @param pEmployeeA
 * @param pEmployeeB
 * @return retorna el resultado de la comparacion de dos cadenas de caracteres
 */
int sortByName(Employee* pEmployeeA, Employee* pEmployeeB) {

	char employeeA[128];
	char employeeB[128];
	int resultCmp;

	employee_getNombre(pEmployeeA, employeeA);
	employee_getNombre(pEmployeeB, employeeB);

	resultCmp = strcmp(employeeA, employeeB);


	return resultCmp;
}



/**
 * @fn int sortByHours(Employee*, Employee*)
 * @brief ordena la lista segun horas trabajadas
 *
 * @param pEmployeeA
 * @param pEmployeeB
 * @return retorna [-1] / [1] segun tamanio
 */
int sortByHours(Employee* pEmployeeA, Employee* pEmployeeB) {

	int employeeA;
	int employeeB;
	int retorno;

	employee_getHorasTrabajadas(pEmployeeA, &employeeA);
	employee_getHorasTrabajadas(pEmployeeB, &employeeB);

	if(employeeA > employeeB) {
		retorno = 1;
	}
	else if (employeeA < employeeB) {
		retorno = -1;
	}

	return retorno;
}



/**
 * @fn int sortBySalary(Employee*, Employee*)
 * @brief ordena la lista segun sueldo
 *
 * @param pEmployeeA
 * @param pEmployeeB
 * @return retorna [-1] / [1] segun tamanio
 */
int sortBySalary(Employee* pEmployeeA, Employee* pEmployeeB) {

	int employeeA;
	int employeeB;
	int retorno;

	employee_getSueldo(pEmployeeA, &employeeA);
	employee_getSueldo(pEmployeeB, &employeeB);

	if(employeeA > employeeB) {
		retorno = 1;
	}
	else if (employeeA < employeeB) {
		retorno = -1;
	}

	return retorno;
}





