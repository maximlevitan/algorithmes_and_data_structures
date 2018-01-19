/**
 * Sort algorithms
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>

#include "helpers.h"

void printArray(int* array, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%6i", array[i]);
    }

    puts("");
}

void fillArrayIntDataFromInput(int* array, int size)
{
    for (int i = 0; i < size; i++) {
        printf("Input %d:", i);
        scanf("%d", &array[i]);
    }
}
