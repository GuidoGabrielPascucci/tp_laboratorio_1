
#ifndef INPUTS_H_
#define INPUTS_H_



int getIntInMinMaxRange(char* message, char* errorMessage, int min, int max);
int getIntAboveMinimum(char* message, char* errorMessage, int min);
float getFloatInMinMaxRange(char* message, char* errorMessage, int min, int max);		// FALTA DOCUMENTAR (Y VALIDAR?)
void getString(char* string, char* message, char* errorMessage, int max);




#endif
