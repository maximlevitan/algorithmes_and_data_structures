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

    (*opCounter)++; // 1 set i = 0 operation
    for (i = 0; i < size; i++) {
        (*opCounter) += 2; // 2 loop operations

        (*opCounter)++; // 1 set j = 0 operation
        for (j = 0; j < size - 1; j++) {
            (*opCounter) += 2; // 2 loop operations

            if (input[j] > input[j + 1]) {
                swapInt(&input[j], &input[j + 1]);

                (*opCounter) += 3; // 3 swap operations
            }

            (*opCounter)++; // 1 check condition operation
        }
    }
}

void boostedBubbleSortInt(int* input, int size, int* opCounter)
{
    int j, swpCounter;

    do {
        swpCounter = 0;
        j = 0;

        (*opCounter) += 2; // 2 set value operation

        for ( ; j < size - 1; j++) {
            (*opCounter) += 2; // 2 loop operations

            if (input[j] > input[j + 1]) {
                swapInt(&input[j], &input[j + 1]);

                swpCounter++;

                (*opCounter) += 4; // 3 swap operations and 1 increment
            }

            (*opCounter)++; // 1 check condition operation
        }

        (*opCounter)++; // 1 loop condition operation
    } while (swpCounter > 0);
}

void shakerSortInt(int* input, int size, int* opCounter)
{
    int i;
	int leftBorder = 1;
	int rightBorder = size - 1;

	(*opCounter) += 2; // 2 set operation2

	while (leftBorder <= rightBorder) {
        (*opCounter)++; // 1 loop condition operation

        (*opCounter)++; // 1 set i = 0 operation
		for (i = rightBorder; i >= leftBorder; i--) {
            (*opCounter) += 2; // 2 loop operations

            if (input[i - 1] > input[i]) {
                swapInt(&input[i], &input[i - 1]);

                (*opCounter) += 3; // 3 swap operations
            }

            (*opCounter)++; // 1 check condition operation
		}

		leftBorder++;

		(*opCounter)++; // 1 set i = 0 operation,
		for (i = leftBorder; i <= rightBorder; i++) {
            (*opCounter) += 2; // 2 loop operations

            if (input[i - 1] > input[i]) {
                swapInt(&input[i], &input[i - 1]);

                (*opCounter) += 3; // 3 swap operations
            }

            (*opCounter)++; // 1 check condition operation
		}

		rightBorder--;

		(*opCounter) += 2; // 2 increment operations
	}
}
