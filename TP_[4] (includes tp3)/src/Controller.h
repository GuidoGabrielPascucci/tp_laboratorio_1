int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


int mostrarMenuPrincipal(void);
void controlador_menuPrincipal(LinkedList* listaEmpleados);
void cargarArchivoDeTexto(LinkedList* listaEmpleados, int* fileIsOpen, int* flag);
void cargarArchivoBinario(LinkedList* listaEmpleados, int* fileIsOpen, int* flag);
void realizarAltaDeEmpleado(LinkedList* listaEmpleados, int flag);
void modificarDatosDeEmpleado(LinkedList* listaEmpleados, int flag);
void eliminarEmpleado(LinkedList* listaEmpleados, int flag) ;
int confirmarRemoverEmpleado(void);
void mostrarListaEmpleados(LinkedList* listaEmpleados, int flag);
void ordenarEmpleados(LinkedList* listaEmpleados, int flag);
void guardarArchivoTexto(LinkedList* listaEmpleados, int flag);
void guardarArchivoBinario(LinkedList* listaEmpleados, int flag);
void mostrarMensajeDespedida(void);
