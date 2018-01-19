/**
 * Sort algorithms
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>

#include "search.h"

int binarySearchInt(int searchValue, int* inputArray, int arraySize, int* opCounter)
{
    int leftIndex = 0;
    int rightIndex = arraySize - 1;
    int curIndex = 0;

    (*opCounter) += 3; // 3 set value operations

    while (leftIndex <= rightIndex) {
        (*opCounter) += 3; // 1 loop condition operation, 1 set operation, 1 check condition operation

        curIndex = (leftIndex + rightIndex) / 2;
        if (searchValue == inputArray[curIndex]) {
            return leftIndex;
        }

        (*opCounter) += 2; // 1 check condition operation, 1 set operation
        if (searchValue < inputArray[curIndex]) {
            rightIndex = curIndex - 1;
        } else {
            leftIndex = curIndex + 1;
        }
    }

    return -1;
}
