#ifndef INPUTS_H_
#define INPUTS_H_



int getIntInMinMaxRange(int* enteredNumber, char* message, char* errorMessage, int min, int max);
int getIntHigherThan(int* enteredNumber, char* message, char* errorMessage, int min);
int getString(char* string, char* message, char* errorMessage, int max);


#endif
