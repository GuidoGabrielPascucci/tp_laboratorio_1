
#include <stdio.h>
#include <stdlib.h>
#include "funcionesTP_1.h"



/**
 * @fn void mostrarMenu(void)
 * @brief ----> Menu del programa con todas las acciones disponibles.
 *
 */
void mostrarMenu(void){
	float numero1;
	float numero2;
	float resultadoDeLaSuma;
	float resultadoDeLaResta;
	float resultadoDeLaMultiplicacion;
	float resultadoDeLaDivision;
	int pudoRealizarDivision;
	int resultadoFactorial1;
	int resultadoFactorial2;
	int opcionDelMenu;
	int validacionResultadosCalculados;

	numero1=0;
	numero2=0;
	opcionDelMenu=0;
	validacionResultadosCalculados=0;

	while(opcionDelMenu!=5)
	{
		printf("\nElija la operaci�n que desea realizar: \n"
				"1. Ingresar 1er operando --> (A = %.2f) \n"
				"2. Ingresar 2do operando --> (B = %.2f) \n"
				"3. Calcular todas las operaciones \n"
				"4. Informar resultados \n"
				"5. Salir\n",numero1,numero2);
		fflush(stdin);
		scanf("%d",&opcionDelMenu);

		if(opcionDelMenu!=5){
			separarCodigo2();
		}

		switch(opcionDelMenu)
		{
			case 1:
				printf("Ingrese primer operando: ");
				fflush(stdin);
				scanf("%f",&numero1);
				validacionResultadosCalculados=0;
				break;

			case 2:
				printf("\nIngrese segundo operando: ");
				fflush(stdin);
				scanf("%f",&numero2);
				validacionResultadosCalculados=0;
				break;

			case 3:
				calcularOperaciones(numero1, numero2, &resultadoDeLaSuma, &resultadoDeLaResta, &resultadoDeLaMultiplicacion, &resultadoDeLaDivision, &pudoRealizarDivision, &resultadoFactorial1, &resultadoFactorial2);
				validacionResultadosCalculados++;
				break;

			case 4:
				mostrarResultados(numero1, numero2, resultadoDeLaSuma, resultadoDeLaResta, resultadoDeLaMultiplicacion, pudoRealizarDivision, resultadoDeLaDivision, resultadoFactorial1, resultadoFactorial2, validacionResultadosCalculados);
				if(validacionResultadosCalculados==1){
					validacionResultadosCalculados--;
				}
				break;

			case 5:
				// exit
				break;

			default:
				printf("La opci�n ingresada no es correcta. Por favor ingresa nuevamente una opci�n. \n\n");
				break;
		}
	}
}



/**
 * @fn void calcularOperaciones(float, float, float*, float*, float*, float*, int*, int*, int*)
 * @brief ----> OBTIENE RESULTADOS de todas las funciones que realizan c�lculos aritm�ticos
 *
 * @param numeroIngresado1
 * @param numeroIngresado2
 * @param punteroResultSuma
 * @param punteroResultResta
 * @param punteroResultMultiplicacion
 * @param punteroResultDivision
 * @param punteroPudoRealizarDivision
 * @param punteroResultFactorial1
 * @param punteroResultFactorial2
 */
void calcularOperaciones(float numeroIngresado1, float numeroIngresado2, float* punteroResultSuma, float* punteroResultResta, float* punteroResultMultiplicacion, float* punteroResultDivision, int* punteroPudoRealizarDivision, int* punteroResultFactorial1, int* punteroResultFactorial2){
	float resultadoDeLaDivision;

	*punteroResultSuma=sumarNumeros(numeroIngresado1,numeroIngresado2);
	*punteroResultResta=restarNumeros(numeroIngresado1,numeroIngresado2);
	*punteroResultMultiplicacion=multiplicarNumeros(numeroIngresado1,numeroIngresado2);
	*punteroPudoRealizarDivision=dividirNumeros(&resultadoDeLaDivision,numeroIngresado1,numeroIngresado2);
	*punteroResultDivision=resultadoDeLaDivision;
	*punteroResultFactorial1=calcularFactorial(numeroIngresado1, FMAX, FMIN);
	*punteroResultFactorial2=calcularFactorial(numeroIngresado2, FMAX, FMIN);

	printf("C�lculos realizados. Presione 4 para ver los resultados. \n");
}



/**
 * @fn void mostrarResultados(float, float, float, float, float, int, float, int, int, int)
 * @brief ----> Valida y MUESTRA en pantalla los resultados obtenidos.
 *
 * @param numeroIngresado1
 * @param numeroIngresado2
 * @param informarResultadoSuma
 * @param informarResultadoResta
 * @param informarResultadoMultiplicacion
 * @param validarDivision
 * @param informarResultadoDivision
 * @param informarResultadoFactorial1
 * @param informarResultadoFactorial2
 * @param validacionResultadosCalculados
 */
void mostrarResultados(float numeroIngresado1, float numeroIngresado2, float informarResultadoSuma, float informarResultadoResta, float informarResultadoMultiplicacion, int validarDivision, float informarResultadoDivision, int informarResultadoFactorial1, int informarResultadoFactorial2, int validacionResultadosCalculados){

	if(validacionResultadosCalculados!=0){
		printf("Resultado de la suma: \t\t\t%.2f + %.2f = %.2f \n",numeroIngresado1,numeroIngresado2,informarResultadoSuma);
		printf("Resultado de la resta: \t\t\t%.2f - %.2f = %.2f \n",numeroIngresado1,numeroIngresado2,informarResultadoResta);
		printf("Resultado de la multiplicaci�n: \t%.2f * %.2f = %.2f \n",numeroIngresado1,numeroIngresado2,informarResultadoMultiplicacion);

		if(validarDivision==0){
			printf("Resultado de la division: \t\t%.2f / %.2f = %.2f \n",numeroIngresado1,numeroIngresado2,informarResultadoDivision);
		} else {
			printf("Resultado de la division: \t\t%.2f / %.2f = Error. No se puede dividir por cero. \n",numeroIngresado1,numeroIngresado2);
		}

		if(informarResultadoFactorial1==-1){
			printf("Resultado del factorial A: \t\t%.2f! = No se pudo realizar el Factorial. Motivo: Entrada no v�lida. \n",numeroIngresado1);
		} else if(informarResultadoFactorial1==0){
			printf("Resultado del factorial A: \t\t%.2f! = No se pudo realizar el Factorial. Motivo: desbordamiento. \n",numeroIngresado1);
		}	else {
			printf("Resultado del factorial A: \t\t%.2f! = %d \n",numeroIngresado1,informarResultadoFactorial1);
		}

		if(informarResultadoFactorial2==-1){
			printf("Resultado del factorial B: \t\t%.2f! = No se pudo realizar el Factorial. Motivo: Entrada no v�lida. \n\n",numeroIngresado2);
		} else if(informarResultadoFactorial2==0){
			printf("Resultado del factorial B: \t\t%.2f! = No se pudo realizar el Factorial. Motivo: desbordamiento. \n\n",numeroIngresado2);
		} else {
			printf("Resultado del factorial B: \t\t%.2f! = %d \n\n",numeroIngresado2,informarResultadoFactorial2);
		}

	} else {
		printf("Error al informar resultados. Motivo: no hay resultados para mostrar. Por favor ingres� los operandos antes de calcular. \n"
				"Si ya ingresaste los operandos presion� 3 para realizar los c�lculos y luego 4 para mostrarlos en pantalla. \n\n");
	}
}



/**
 * @fn float sumarNumeros(float, float)
 * @brief ----> Realiza la operaci�n de SUMA de los n�meros ingresados.
 *
 * @param numeroIngresado1 ----> Primer operando ingresado (A).
 * @param numeroIngresado2 ----> Segundo operando ingresado (B).
 * @return ----> Retorna el RESULTADO DE LA SUMA de los operandos ingresados.
 */
float sumarNumeros(float numeroIngresado1, float numeroIngresado2)
{
	float result;
	result = numeroIngresado1+numeroIngresado2;
	return result;
}



/**
 * @fn float restarNumeros(float, float)
 * @brief ----> Realiza la operaci�n de RESTA de los n�meros ingresados.
 *
 * @param numeroIngresado1 ----> Primer operando ingresado (A).
 * @param numeroIngresado2 ----> Segundo operando ingresado (B).
 * @return ----> Retorna el RESULTADO DE LA RESTA de los operandos ingresados.
 */
float restarNumeros(float numeroIngresado1, float numeroIngresado2)
{
	float result;
	result = numeroIngresado1-numeroIngresado2;
	return result;
}



/**
 * @fn float multiplicarNumeros(float, float)
 * @brief ----> Realiza la operaci�n de MULTIPLICACI�N de los n�meros ingresados.
 *
 * @param numeroIngresado1 ----> Primer operando ingresado (A).
 * @param numeroIngresado2 ----> Segundo operando ingresado (B).
 * @return ----> Retorna el RESULTADO DE LA MULTIPLICACI�N de los operandos ingresados.
 */
float multiplicarNumeros(float numeroIngresado1, float numeroIngresado2)
{
	float result;
	result = numeroIngresado1*numeroIngresado2;
	return result;
}



/**
 * @fn int dividirNumeros(float*, float, float)
 * @brief ----> Realiza la operaci�n de DIVISI�N de los n�meros ingresados.
 *
 * @param resultDivision ----> Puntero a variable que guardar� el RESULTADO DE LA DIVISI�N de los n�meros ingresados.
 * @param numeroIngresado1 ----> Primer operando ingresado (A).
 * @param numeroIngresado2 ----> Segundo operando ingresado (B).
 * @return ----> Retorna un VALOR que informa si la funci�n PUDO REALIZAR LA DIVISI�N O NO.
 */
int dividirNumeros(float* resultDivision, float numeroIngresado1, float numeroIngresado2)
{
	float result;
	int retornoFunction;
	retornoFunction=-1;

	if(resultDivision!=NULL && numeroIngresado2!=0)
	{
		result=numeroIngresado1/numeroIngresado2;
		*resultDivision=result;
		retornoFunction=0;
	}

	return retornoFunction;
}



/**
 * @fn int calcularFactorial(int, int, int)
 * @brief ----> Realiza la operaci�n de FACTORIAL del numero ingresado.
 *
 * @param operandoIngresado ----> N�mero ingresado sobre el cual se realizar� la operaci�n.
 * @param maximo ----> N�mero m�ximo para realizar la operaci�n sin obtener un desbordamiento.
 * @param minimo ----> N�mero m�nimo para realizar la operaci�n sin obtener como resultado una entrada no v�lida.
 * @return ----> Retorna el RESULTADO DEL FACTORIAL del operando ingresado.
 */
int calcularFactorial(int operandoIngresado, int maximo, int minimo)
{
	int factorial;

	if(operandoIngresado > maximo)
	{
		factorial=0;
	}
	else
	{
		if(operandoIngresado < minimo)
		{
			factorial=-1;
		}
		else
		{
			if((operandoIngresado != 1) && (operandoIngresado != 0))
			{
				factorial=(int)operandoIngresado*calcularFactorial(operandoIngresado-1, maximo, minimo);
			}
			else
			{
				factorial=1;
			}
		}
	}

	return factorial;
}



/**
 * @fn void separarCodigo(void)
 * @brief ----> Separador de asteriscos (*) para embellecer el men� de opciones
 *
 */
void separarCodigo(void)
{
	printf("\n******************************************************************************************************************************************************************\n\n");
}



/**
 * @fn void separarCodigo2(void)
 * @brief ----> Separador de guiones (-) para embellecer el men� de opciones
 *
 */
void separarCodigo2(void)
{
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
}



