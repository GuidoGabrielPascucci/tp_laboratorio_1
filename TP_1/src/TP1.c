
#include <stdio.h>
#include <stdlib.h>
#include "funcionesTP_1.h"


int main (void){
	setbuf(stdout, NULL);

	separarCodigo();
	printf("\nHola! Gracias por elegir nuestro servicio de cálculo rápido :) \n"
			"*BIENVENIDOS A CALCULIN* \n\n");
	separarCodigo();
	system("pause");

	mostrarMenu();

	separarCodigo();
	printf("\n\t\t Gracias por utilizar CALCULIN. Hasta la próxima! \n\n");
	separarCodigo();
	return EXIT_SUCCESS;
}
