
#ifndef FUNCIONESTP_1_H_
#define FUNCIONESTP_1_H_
#define FMAX 12
#define FMIN 0


void mostrarMenu(void);
void calcularOperaciones(float numeroIngresado1, float numeroIngresado2, float* punteroResultSuma, float* punteroResultResta, float* punteroResultMultiplicacion, float* punteroResultDivision, int* punteroPudoRealizarDivision, int* punteroResultFactorial1, int* punteroResultFactorial2);
void mostrarResultados(float numeroIngresado1, float numeroIngresado2, float informarResultadoSuma, float informarResultadoResta, float informarResultadoMultiplicacion, int validarDivision, float informarResultadoDivision, int informarResultadoFactorial1, int informarResultadoFactorial2, int validacionResultadosCalculados);
float sumarNumeros(float numeroIngresado1, float numeroIngresado2);
float restarNumeros(float numeroIngresado1, float numeroIngresado2);
float multiplicarNumeros(float numeroIngresado1, float numeroIngresado2);
int dividirNumeros(float* resultDivision, float numeroIngresado1, float numeroIngresado2);
int calcularFactorial(int operandoIngresado, int maximo, int minimo);
void separarCodigo(void);
void separarCodigo2(void);


#endif
