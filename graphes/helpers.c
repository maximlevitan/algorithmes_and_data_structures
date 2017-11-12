/**
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "helpers.h"

int isNumber(char* string)
{
    int i = 0;
    while (string[i] != '\0') {
        if (!isdigit(string[i++])) {
            return 0;
        }
    }

    return 1;
}

void printArray(int* array, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%6i", array[i]);
    }

    puts("");
}

void print2DArray(int* array2d, int rowCount, int colCount)
{
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            printf("%6i", *((array2d + i * rowCount) + j));
        }

        puts("");
    }
}

void fillArrayIntDataFromInput(int* array, int size)
{
    for (int i = 0; i < size; i++) {
        printf("Input %d:", i);
        scanf("%d", &array[i]);
    }
}

void fill2DArrayIntByValue(int* array2d, int rowCount, int colCount, int value)
{
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            *((array2d + i * rowCount) + j) = value;
        }
    }
}

int randNumber(int min, int max)
{
    return rand() % (max + 1 - min) + min;
}
