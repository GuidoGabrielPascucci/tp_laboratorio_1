/*
 ============================================================================
 Name        : TP_[4].c
 Author      : Pascucci, Guido 1-D
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Inputs.h"


int main() {
	setbuf(stdout, NULL);

    LinkedList* listaEmpleados = ll_newLinkedList();
    controlador_menuPrincipal(listaEmpleados);
    ll_deleteLinkedList(listaEmpleados);


    return 0;
}

