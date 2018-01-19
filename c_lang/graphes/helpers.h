#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED

int isNumber(char* string);

void printArray(int* array, int size);

void print2DArray(int* array2d, int rowCount, int colCount);

void fillArrayIntDataFromInput(int* array, int size);

void fillArrayIntByValue(int* array, int size, int value);

void fill2DArrayIntByValue(int* array2d, int rowCount, int colCount, int value);

int randNumber(int min, int max);

#endif // HELPERS_H_INCLUDED
