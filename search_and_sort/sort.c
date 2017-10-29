/**
 * Sort algorithms
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>

#include "sort.h"

void swapInt(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleSortInt(int* input, int size, int* opCounter)
{
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size - 1; j++) {
            if (input[j] > input[j + 1]) {
                swapInt(&input[j], &input[j + 1]);

                (*opCounter) += 3;
            }

            (*opCounter)++;
        }
    }
}

void boostedBubbleSortInt(int* input, int size, int* opCounter)
{
    int i, j;
    int jmax = 0;
    int jmin = 0;
    int start = 0;
    int end = size;

    for (i = 0; i < end; i++) {
        jmax = i;
        jmin = i;
        (*opCounter) += 2;

        for (j = start; j < end - 1; j++) {
            if (input[j] > input[j + 1]) {
                jmin = j + 1;
                swapInt(&input[j], &input[j + 1]);

                (*opCounter) += 4;
            } else {
                jmax = j + 1;
                (*opCounter)++;
            }

            (*opCounter)++;
        }

        if (j == jmax) {
            end--;
        }

        if (j == jmin) {
            start--;
        }

        (*opCounter) += 2;
    }
}
