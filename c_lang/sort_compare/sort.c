/**
 * Sort algorithms
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"
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

void simpleCountingSortInt(int* input, int size, int maxValue, int* opCounter)
{
    int i, j;
    int counter = 0;

    int* countingArray = (int*) malloc(maxValue * sizeof(int));
    if (countingArray == NULL) {
        printf("Can`t allocate some dynamic memory for counting array.\n");

        return;
    }

    fillArrayIntByValue(countingArray, maxValue, 0);

    // 1 operation for allocate memory and + maxValue operations of filling array with 0 values and + 2 set i and counter,
    (*opCounter) += maxValue + 2;

    for (i = 0; i < maxValue; i++) {
        (*opCounter) += 3; // 2 loop operations + 1 set counting array value

        // Dynamic analog for: countingArray[input[i]]++;
        *(countingArray + *(input + i)) += 1;
    }

    (*opCounter) += 1; // 1 for set j
    for (j = 0; j < maxValue; j++) {
        (*opCounter) += 3; // 2 loop operations + 1 for set i

        // Expression *(countingArray + j) - 1 is dynamic analog for: countingArray[j] - 1;
        for (i = 0; i < *(countingArray + j) - 1; i++) {
            (*opCounter) += 4; // 2 loop operations and + 2 sets counter and input array

            // Dynamic analog for: input[counter++] = j;
            *(input + counter++) = j;
        }
    }

    free(countingArray);
}

/**
 * Quick Sort algorithm
 *
 * With Recursion.
 * Fastest algorithm with complexity: O(n * log n), and O(n**2) in bed variant
 * But have big problem on big N: make N-level recursion (may be memory limit problem).
 */
void quickSortInt(int* input, int first, int last, int* opCounter)
{
    int left = first;
    int right = last;

    (*opCounter) += 2; // 2 sets

    if (last < 1 || first == last) {
        return;
    }

    // 1 STEP: find middle value in array keys interval from first to last
    int middleValue = *(input + ((first + last) >> 1));

    (*opCounter) += 3; // 1 sets and +1 expression and +1 condition

    // 2 STEP: reorganize array in left side first (then middle value) elements,
    // in right side last (then middle value) elements
    do {
        // Move left index to the middle element, while left index value not higher, then middle one
        while (*(input + left) < middleValue) {
            left++;

            (*opCounter) += 2; // 1 loop condition and +1 counting left
        }

        // Move right index to the middle element, while right index value higher, then middle one
        while (*(input + right) > middleValue) {
            right--;

            (*opCounter) += 2; // 1 loop condition and +1 counting right
        }

        if (left <= right) {
            swapInt(input + left, input + right);

            left++, right--;

            (*opCounter) += 5; // 3 of swapping an + 2 counting
        }

        (*opCounter) += 1; // 1 condition
    } while (left <= right);

    // 3 STEP: recursively sort of two parts of array
    // Recursively sort first part of array (or partial)
    (*opCounter) += 1; // 1 condition
    if (right > first) {
        quickSortInt(input, first, right, opCounter);
    }

    // Recursively sort second part of array (or partial)
    (*opCounter) += 1; // 1 condition
    if (left < last) {
        quickSortInt(input, left, last, opCounter);
    }
}

/**
 * Merge Sort algorithm (recursion version)
 */
void recursionMergeSortInt(int* input, int left, int right, int* opCounter)
{
    int middle;

    (*opCounter) += 1; // 1 condition
    if (left >= right) {
        return;
    }

    (*opCounter) += 1; // 1 condition
    if (right - left == 1) {
        if (*(input + right) < *(input + left)) {
            swapInt(input + left, input + right);

            (*opCounter) += 4; // 1 condition + 3 swapping
        }

        return;
    }

    middle = ((left + right) >> 1);

    (*opCounter) += 2; // 1 set and +1 calc

    recursionMergeSortInt(input, left, middle, opCounter);
    recursionMergeSortInt(input, middle + 1, right, opCounter);

    mergeArrayIntParts(input, left, middle, right, opCounter);
}

/**
 * Merges two parts in input array.
 */
void mergeArrayIntParts(int* input, int left, int middle, int right, int* opCounter)
{
    int i, j, key = left;

    (*opCounter) += 2; // 3 sets

    int sizeLeft = middle + 1 - left;
    int sizeRight = right - middle;

    int partLeft[sizeLeft], partRight[sizeRight];

    for (i = 0; i < sizeLeft; i++) {
        (*opCounter) += 3; // 2 loop operations and 1 set

        partLeft[i] = *(input + left + i);
    }

    for (j = 0; j < sizeRight; j++) {
        (*opCounter) += 3; // 2 loop operations and 1 set

        partRight[j] = *(input + middle + 1 + j);
    }

    i = 0;
    j = 0;
    while (i < sizeLeft && j < sizeRight) {
        (*opCounter) += 2; // 2 logic operation

        if (partLeft[i] <= partRight[j]) {
            *(input + key) = partLeft[i];
            i++;

            (*opCounter) += 2; // 2 sets
        } else {
            *(input + key) = partRight[j];
            j++;

            (*opCounter) += 2; // 2 sets
        }

        key++;

        (*opCounter) += 1; // 1 set
    }

    while (i < sizeLeft) {
        (*opCounter) += 4; // 1 logic + 3 sets

        *(input + key) = partLeft[i];

        i++, key++;
    }

    while (j < sizeRight) {
        (*opCounter) += 4; // 1 logic + 3 sets

        *(input + key) = partRight[j];

        j++, key++;
    }
}

