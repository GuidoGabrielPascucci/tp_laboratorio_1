#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"

#include "Inputs.h"

#define ID 1001
#define SIZE_NAME 128
#define SIZE_INT 11


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee) {

	int retorno = 0;
	FILE *pFile = fopen(path, "r");
	retorno = parser_EmployeeFromText(pFile, pArrayListEmployee);
	fclose(pFile);

    return retorno;
}




/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee) {

	int retorno = 0;
	FILE *pFile = fopen(path, "rb");
	retorno = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
	fclose(pFile);

    return retorno;
}




/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee) {

	int retorno = 0;
	Employee *pEmployee = NULL;
	pEmployee = employee_new();

	retorno = cargarDatosDeEmpleado(pArrayListEmployee, pEmployee);
	ll_add(pArrayListEmployee, pEmployee);

    return retorno;
}







/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_editEmployee(LinkedList* pArrayListEmployee) {

	int retorno = -1;
	int selectedID;
	int index = -1;
	Employee *pEmployee = NULL;

	if(pArrayListEmployee != NULL) {

		do{
			controller_ListEmployee(pArrayListEmployee);

			getIntHigherThan(&selectedID, "\n\n-------------------------------------------------------------------------------------------------------------------\n"
										  "Ingrese el ID del empleado que desee modificar: ",

										  "\n\n-------------------------------------------------------------------------------------------------------------------\n"
										  "ERROR <<Entrada invalida - El ID debe ser un numero entero mayor a cero>>\n"
										  "Por favor reingrese el ID del empleado que desee modificar: ", 0);


			for (int i = 0; i < ll_len(pArrayListEmployee); ++i) {

				pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

				if(selectedID == pEmployee->id) {
					index = i;
					break;
				}
			}


			if(index == -1) {
				printf("\nERROR <<ID no encontrado>>\n"
						"El ID seleccionado no pertenece a ningun empleado cargado en la lista\n\n");
				system("pause");
			}

		} while(index == -1);


		retorno = editarEmpleado(pEmployee);
	}




	return retorno;
}




/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee) {

	int retorno = -1;
	int selectedID;
	int index = -1;
	Employee *pEmployee = NULL;


	if(pArrayListEmployee != NULL) {

		do{
			controller_ListEmployee(pArrayListEmployee);

			getIntHigherThan(&selectedID, "\n\n-------------------------------------------------------------------------------------------------------------------\n"
										  "Ingrese el ID del empleado que desee remover de la lista: ",

										  "\n\n-------------------------------------------------------------------------------------------------------------------\n"
										  "ERROR <<Entrada invalida - El ID debe ser un numero entero mayor a cero>>\n"
										  "Por favor reingrese el ID del empleado que desee remover de la lista: ", 0);


			for (int i = 0; i < ll_len(pArrayListEmployee); ++i) {

				pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

				if(selectedID == pEmployee->id) {
					index = i;
					break;
				}
			}

			if(index == -1) {
				printf("\nERROR <<ID no encontrado>>\n"
						"El ID seleccionado no pertenece a ningun empleado cargado en la lista\n\n");
				system("pause");
			}

		} while(index == -1);


		retorno = removerEmpleado(pEmployee, pArrayListEmployee, index);
	}


	return retorno;
}







/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee) {

	Employee *pEmployee = NULL;
	int retorno = 0;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	printf("\n\n\n\nLISTA DE EMPLEADOS\n"
			"-------------------------------------------------------------------------------------------------------------------\n"
			"%-20s %-30s %-35s %-10s", "ID", "Nombre", "Horas Trabajadas", "Sueldo\n"
			"-------------------------------------------------------------------------------------------------------------------\n" );

	for (int i = 0; i < ll_len(pArrayListEmployee); ++i) {

		pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

		employee_getId(pEmployee, &id);
		employee_getNombre(pEmployee, nombre);
		employee_getHorasTrabajadas(pEmployee, &horasTrabajadas);
		employee_getSueldo(pEmployee, &sueldo);

		pEmployee = NULL;
		printf("%-20d %-30s %-35d %-10d\n", id, nombre, horasTrabajadas, sueldo);
	}


    return retorno;
}




/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee) {

	int retorno = 0;
	int option;
	int criterioDeOrdenamiento;

	int (*pSortByID)() = sortByID;
	int (*pSortByName)() = sortByName;
	int (*pSortByHours)() = sortByHours;
	int (*pSortBySalary)() = sortBySalary;


	if(pArrayListEmployee != NULL) {


		getIntInMinMaxRange(&option, "\n\n\nSeleccione la opcion de ordenamiento que desee:\n"
									 	   "-------------------------------------------------------------------------------------------------------------------\n"
									 	   "1. ID\n"
									 	   "2. Nombre\n"
									 	   "3. Horas Trabajadas\n"
									 	   "4. Sueldo\n\n\n",


									 "\n\n\nERROR <<Opcion no valida>>\n"
										   "Seleccione la opcion de ordenamiento que desee:\n"
										   "-------------------------------------------------------------------------------------------------------------------\n"
										   "1. ID\n"
										   "2. Nombre\n"
										   "3. Horas Trabajadas\n"
										   "4. Sueldo\n\n\n", 1, 4);


		getIntInMinMaxRange(&criterioDeOrdenamiento, "\nSeleccione el criterio de ordenamiento:\n"
													   "-------------------------------------------------------------------------------------------------------------------\n"
													   "0. Descendente\n"
													   "1. Ascendente\n",

													 "\nERROR <<Opcion no valida>>\n"
													   "Seleccione el criterio de ordenamiento:\n"
													   "-------------------------------------------------------------------------------------------------------------------\n"
													   "0. Descendente\n"
													   "1. Ascendente\n", 0, 1);




		switch(option) {
			case 1:
				ll_sort(pArrayListEmployee, pSortByID, criterioDeOrdenamiento);
				break;

			case 2:
				ll_sort(pArrayListEmployee, pSortByName, criterioDeOrdenamiento);
				break;

			case 3:
				ll_sort(pArrayListEmployee, pSortByHours, criterioDeOrdenamiento);
				break;

			case 4:
				ll_sort(pArrayListEmployee, pSortBySalary, criterioDeOrdenamiento);
				break;
		}

		retorno = 1;
	}


	return retorno;
}






/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee) {

	int retorno = 0;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	Employee *pEmployee = NULL;
	FILE *pFile = fopen(path, "w");

	if(pFile != NULL && pArrayListEmployee != NULL) {

		fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");

		for (int i = 0; i < ll_len(pArrayListEmployee); ++i) {
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

			employee_getId(pEmployee, &id);
			employee_getNombre(pEmployee, nombre);
			employee_getHorasTrabajadas(pEmployee, &horasTrabajadas);
			employee_getSueldo(pEmployee, &sueldo);

			fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
			pEmployee = NULL;
		}

		fclose(pFile);
		retorno = 1;
	}


    return retorno;
}




/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee) {

	int retorno = 0;
	Employee *pEmployee = NULL;
	FILE *pFile = fopen(path, "wb");

	if(pFile != NULL && pArrayListEmployee != NULL) {

		for (int i = 0; i < ll_len(pArrayListEmployee); ++i) {
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(pEmployee, sizeof(Employee), 1, pFile);
			pEmployee = NULL;
		}

		fclose(pFile);
		retorno = 1;
	}


    return retorno;
}







/**
 * @fn int mostrarMenuPrincipal(void)
 * @brief muestra el menu principal con todas las acciones disponibles
 *
 * @return retorna un numero que sera la opcion que haya elegido el usuario
 */
int mostrarMenuPrincipal(void) {

	int option;

	getIntInMinMaxRange(&option, "\n===================================================================================================================\n\n"
								 "MENU\n\n"
								 "===================================================================================================================\n"
								 "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
								 "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
								 "3. Alta de empleado\n"
								 "4. Modificar datos de empleado\n"
								 "5. Baja de empleado\n"
								 "6. Listar empleados\n"
								 "7. Ordenar empleados\n"
								 "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
								 "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n\n"
								 "10. Salir\n"
								 "===================================================================================================================\n\n"
								 "Ingrese una opcion: ",


								 "\n\n\nERROR! <<La opcion ingresada no es correcta>>\n"
								 "===================================================================================================================\n"
								 "MENU\n\n"
								 "===================================================================================================================\n"
								 "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
								 "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
								 "3. Alta de empleado\n"
								 "4. Modificar datos de empleado\n"
								 "5. Baja de empleado\n"
								 "6. Listar empleados\n"
								 "7. Ordenar empleados\n"
								 "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
								 "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n\n"
								 "10. Salir\n"
								 "===================================================================================================================\n\n"
								 "Reingrese una opcion: ", 1, 10);


	return option;
}



/**
 * @fn void controlador_menuPrincipal(LinkedList*)
 * @brief el controlador donde se ubican todas las acciones disponibles del programa
 *
 * @param listaEmpleados
 */
void controlador_menuPrincipal(LinkedList* listaEmpleados) {

	int fileIsOpen = 0;
	int flag = 0;
	int option;

    do{
    	option = mostrarMenuPrincipal();

        switch(option) {

            case 1:
            	cargarArchivoDeTexto(listaEmpleados, &fileIsOpen, &flag);
                break;

            case 2:
            	cargarArchivoBinario(listaEmpleados, &fileIsOpen, &flag);
            	break;

            case 3:
            	realizarAltaDeEmpleado(listaEmpleados, flag);
            	break;

            case 4:
            	modificarDatosDeEmpleado(listaEmpleados, flag);
            	break;

            case 5:
            	eliminarEmpleado(listaEmpleados, flag);
            	break;

            case 6:
            	mostrarListaEmpleados(listaEmpleados, flag);
            	break;

            case 7:
            	ordenarEmpleados(listaEmpleados, flag);
            	break;

            case 8:
            	guardarArchivoTexto(listaEmpleados, flag);
            	break;

            case 9:
            	guardarArchivoBinario(listaEmpleados, flag);
            	break;

            case 10:
            	mostrarMensajeDespedida();
            	break;
        }

    } while(option != 10);
}



/**
 * @fn void cargarArchivoDeTexto(LinkedList*, int*, int*)
 * @brief carga un archivo de texto al sistema
 *
 * @param listaEmpleados
 * @param fileIsOpen
 * @param flag
 */
void cargarArchivoDeTexto(LinkedList* listaEmpleados, int* fileIsOpen, int* flag) {

	if(!(*fileIsOpen)) {
		if(controller_loadFromText("dataText.csv", listaEmpleados)) {

			printf("\n\n\n*******************************************************************************************************************\n\n"
					"Se ha cargado el archivo de texto exitosamente!\n\n"
					"*******************************************************************************************************************\n\n");

			*flag = 1;
			*fileIsOpen = 1;
		}
		else {
			printf("\n\n\nError al abrir el archivo\n\n");
		}

	}
	else {
		printf("\n\nERROR. <<Operacion no valida>>\n"
				"Ya has cargado los datos del archivo .csv al sistema!\n\n\n");
	}

	system("pause");
}



/**
 * @fn void cargarArchivoBinario(LinkedList*, int*, int*)
 * @brief carga un archivo binario al sistema
 *
 * @param listaEmpleados
 * @param fileIsOpen
 * @param flag
 */
void cargarArchivoBinario(LinkedList* listaEmpleados, int* fileIsOpen, int* flag) {

	if(!(*fileIsOpen)) {
		if(controller_loadFromBinary("dataBinary.csv", listaEmpleados)) {

			printf("\n\n\n*******************************************************************************************************************\n\n"
					"Se ha cargado el archivo binario exitosamente!\n\n"
					"*******************************************************************************************************************\n\n");

			*flag = 1;
			*fileIsOpen = 1;
		}
		else {
			printf("\n\n\nError al abrir el archivo\n\n");
		}

	}
	else {
		printf("\n\nERROR. <<Operacion no valida>>\n"
				"Ya has cargado los datos del archivo .csv al sistema!\n\n\n");
	}

	system("pause");

}



/**
 * @fn void realizarAltaDeEmpleado(LinkedList*, int)
 * @brief realiza un alta de empleado en el sistema
 *
 * @param listaEmpleados
 * @param flag
 */
void realizarAltaDeEmpleado(LinkedList* listaEmpleados, int flag) {

	if(flag) {
		if(controller_addEmployee(listaEmpleados)) {

			printf("\n\n\n*******************************************************************************************************************\n\n"
					"Se ha cargado un empleado exitosamente!\n\n"
					"*******************************************************************************************************************\n\n");
		}
		else {
			printf("\n\n\nERROR! <<No se ha podido cargar el empleado en el sistema>>\n");
		}

	}
	else {
		printf("\n\n\nERROR! <<No hay empleados cargados en el sistema>>\n");
	}

	system("pause");
}




/**
 * @fn void modificarDatosDeEmpleado(LinkedList*, int)
 * @brief modifica los datos que posea el empleado en la lista
 *
 * @param listaEmpleados
 * @param flag
 */
void modificarDatosDeEmpleado(LinkedList* listaEmpleados, int flag) {

	int retorno;

	if(flag) {
		do{
			retorno = controller_editEmployee(listaEmpleados);

			switch(retorno) {
			case -1:
				printf("\n\n\nERROR! <<Lista nula>>\n");
				system("pause");
				break;

			case 0:
				printf("\n\n\n*******************************************************************************************************************\n\n"
						"Se han modificado los datos del empleado exitosamente!\n\n"
						"*******************************************************************************************************************\n\n");
				system("pause");
				break;

			case 1:
				printf("\n\n\nNo se han modificado los datos del empleado\n");
				system("pause");
				break;
			}

			if(!retorno || retorno == 1) {
				getIntInMinMaxRange(&retorno, "\n\n¿Que desea realizar?\n"
											  "-------------------------------------------------------------------------------------------------------------------\n"
											  "1. Modificar datos de empleado\n"
											  "2. Volver al Menu Principal\n\n\n",

											  "\n\nERROR! <<Opcion invalido>>\n"
											  "Por favor reingrese una opcion...\n\n"
											  "¿Desea modificar datos de empleado?\n"
											  "-------------------------------------------------------------------------------------------------------------------\n"
											  "1. Modificar datos de empleado\n"
											  "2. Volver al Menu Principal\n\n\n", 1, 2);

				switch (retorno) {
				case 2:
					retorno = -1;
					break;
				}
			}

		} while(retorno != -1 && retorno != 3);
	}
	else {
		printf("\n\n\nERROR! <<No hay empleados cargados en el sistema>>\n");
		system("pause");
	}

	printf("\n");
}



/**
 * @fn void eliminarEmpleado(LinkedList*, int)
 * @brief remueve un empleado de la lista
 *
 * @param listaEmpleados
 * @param flag
 */
void eliminarEmpleado(LinkedList* listaEmpleados, int flag) {

	int retorno;

	if(flag) {
		do {
			retorno = controller_removeEmployee(listaEmpleados);

			switch(retorno) {
			case -1:
				printf("\n\n\nERROR! <<Lista nula>>\n");
				system("pause");
				break;

			case 0:
				printf("\n\n\n*******************************************************************************************************************\n\n"
						"Se ha removido un empleado exitosamente!\n\n"
						"*******************************************************************************************************************\n\n");
				system("pause");
				break;

			case 1:
				printf("\n\n\n* El empleado sigue cargado en el sistema\n");
				system("pause");
				break;
			}

			if(!retorno || retorno == 1) {
				getIntInMinMaxRange(&retorno, "\n\n¿Que desea realizar?\n"
											  "-------------------------------------------------------------------------------------------------------------------\n"
											  "1. Eliminar un empleado\n"
											  "2. Volver al Menu Principal\n\n\n",

											  "\n\nERROR! <<Opcion invalida>>\n"
											  "Por favor reingrese una opcion...\n\n"
											  "¿Desea eliminar un empleado de la lista?\n"
											  "-------------------------------------------------------------------------------------------------------------------\n"
											  "1. Eliminar un empleado\n"
											  "2. Volver al Menu Principal\n\n\n", 1, 2);

				switch (retorno) {
				case 2:
					retorno = -1;
					break;
				}
			}

		} while(retorno != -1 && retorno != 3);

	}
	else {
		printf("\n\n\nERROR! <<No hay empleados cargados en el sistema>>\n");
		system("pause");
	}

	printf("\n");
}



/**
 * @fn int confirmarRemoverEmpleado(void)
 * @brief muestra un mensaje de seguridad para pedirle al usuario la confirmacion al eliminar un empleado de la lista
 *
 * @return retorna [1] si ELIMINA EMPLEADO / [0] si NO
 */
int confirmarRemoverEmpleado(void) {

	int option;
	getIntInMinMaxRange(&option, "\n\n-------------------------------------------------------------------------------------------------------------------\n"
								 "¿Confirma que desea borrar este empleado de la lista?\n"
								 "-------------------------------------------------------------------------------------------------------------------\n"
								 "1. SI, Eliminar Empleado\n"
								 "0. NO, Cancelar\n\n\n",

								 "\n\nERROR <<La opcion ingresada no es valida>>\n"
								 "Por favor reingrese una opcion...\n"
								 "-------------------------------------------------------------------------------------------------------------------\n"
								 "¿Confirma que desea borrar este empleado de la lista?\n"
								 "-------------------------------------------------------------------------------------------------------------------\n"
								 "1. SI, Eliminar Empleado\n"
								 "0. NO, Cancelar\n\n\n", 0, 1);

	return option;
}





/**
 * @fn void mostrarListaEmpleados(LinkedList*, int)
 * @brief muestra un listado de los empleados cargados en el sistema
 *
 * @param listaEmpleados
 * @param flag
 */
void mostrarListaEmpleados(LinkedList* listaEmpleados, int flag) {

	if(flag) {
		controller_ListEmployee(listaEmpleados);
		printf("\n\n");
	}
	else {
		printf("\n\n\nERROR! <<No hay empleados cargados en el sistema>>\n\n");
	}

	system("pause");
}





/**
 * @fn void ordenarEmpleados(LinkedList*, int)
 * @brief ordena los empleados segun el criterio seleccionado por el usuario
 *
 * @param listaEmpleados
 * @param flag
 */
void ordenarEmpleados(LinkedList* listaEmpleados, int flag) {

	if(flag) {
		if(controller_sortEmployee(listaEmpleados)) {

			printf("\n\n\n*******************************************************************************************************************\n\n"
					"Se han ordenado los datos exitosamente!\n\n"
					"*******************************************************************************************************************\n\n");
		}
		else {
			printf("\n\nHa ocurrido un error...\n\n");
		}

	}
	else {
		printf("\n\n\nERROR! <<No hay empleados cargados en el sistema>>\n");
	}

	system("pause");
}




/**
 * @fn void guardarArchivoTexto(LinkedList*, int)
 * @brief guarda la informacion actual de los empleados en el archivo de texto
 *
 * @param listaEmpleados
 * @param flag
 */
void guardarArchivoTexto(LinkedList* listaEmpleados, int flag) {

	if(flag) {
		if(controller_saveAsText("dataText.csv", listaEmpleados)) {

			printf("\n\n\n*******************************************************************************************************************\n\n"
					"Se ha guardado el archivo de texto exitosamente!\n\n"
					"*******************************************************************************************************************\n\n");
		}
		else {
			printf("\n\n\nError al abrir el archivo\n\n");
		}
	}

	else {
		printf("\n\n\nERROR! <<No hay empleados cargados en el sistema>>\n");
	}

	system("pause");
}





/**
 * @fn void guardarArchivoBinario(LinkedList*, int)
 * @brief guarda la informacion actual de los empleados en el archivo binario
 *
 * @param listaEmpleados
 * @param flag
 */
void guardarArchivoBinario(LinkedList* listaEmpleados, int flag) {

	if(flag) {
		if(controller_saveAsBinary("dataBinary.csv", listaEmpleados)) {

			printf("\n\n\n*******************************************************************************************************************\n\n"
					"Se ha guardado el archivo binario exitosamente!\n\n"
					"*******************************************************************************************************************\n\n");
		}
		else {
			printf("\n\n\nError al abrir el archivo\n\n");
		}

	}
	else {
		printf("\n\n\nERROR! <<No hay empleados cargados en el sistema>>\n");
	}

	system("pause");
}




/**
 * @fn void mostrarMensajeDespedida(void)
 * @brief muestra el mensaje de finalizacion del programa
 *
 */
void mostrarMensajeDespedida(void) {

	printf("\n\n\n"
			"===================================================================================================================\n"
			"Programa finalizado!\n"
			"===================================================================================================================");
}




