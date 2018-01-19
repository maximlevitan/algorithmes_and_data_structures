/**
 * Sort compare
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "helpers.h"
#include "sort.h"

int main(int argc, const char* argv[])
{
    int result = 0;
    int operationCounter = 0;
    int originalInputArray[1000];
    int testArray[1000];
    int arraySize = 1000;

    clock_t startTimeNSec, endTimeNSec;
    float timeDiffInMSec;

    generateRandomArrayIntValues((int*) originalInputArray, arraySize);

    //puts("Array before sort");
    //printArray((int*) originalInputArray, arraySize);

    // task 1:
    // O(100) = [841, 851] = 8.5 * 100 operations, 0.03 milliseconds;
    // O(1000) = [8423, 8527] = 8.5 * 1000 operations, 0.038 milliseconds;
    // O(1000000) = 8471935 operations = 8.5 * 1000000, 17.712999 milliseconds;
    operationCounter = 0;
    copyArrayInt((int*) originalInputArray, arraySize, (int*) testArray);

    startTimeNSec = clock();
    simpleCountingSortInt((int*) testArray, arraySize, arraySize, &operationCounter);
    endTimeNSec = clock();

    timeDiffInMSec = ((float) (endTimeNSec - startTimeNSec) / 1000000.0f) * 1000;
    printf("Total operations and time sorting by simple counting sort: %d op., %f ms\n", operationCounter, timeDiffInMSec);

    // task 2:
    // O(100) = [2519, 2783] operations, 0.007 milliseconds;
    // O(1000) = [35192, 41566] operations, 0.087 milliseconds;
    // O(1000000) = [67550785, 70693486] operations, 143.811005 milliseconds;
    operationCounter = 0;
    copyArrayInt((int*) originalInputArray, arraySize, (int*) testArray);

    startTimeNSec = clock();
    quickSortInt((int*) testArray, 0, arraySize - 1, &operationCounter);

    endTimeNSec = clock();

    timeDiffInMSec = ((float) (endTimeNSec - startTimeNSec) / 1000000.0f) * 1000;
    printf("Total operations and time sorting by quick sort: %d op., %f ms\n", operationCounter, timeDiffInMSec);

    // task 3:
    // O(100) = [5262, 5286] operations, 0.01 milliseconds;
    // O(1000) = [76199, 76341] operations, 0.12 milliseconds;
    // O(1000000) = [132641706, 132644122] operations, 174.79002 milliseconds;
    operationCounter = 0;
    copyArrayInt((int*) originalInputArray, arraySize, (int*) testArray);

    startTimeNSec = clock();
    recursionMergeSortInt((int*) testArray, 0, arraySize - 1, &operationCounter);

    endTimeNSec = clock();

    timeDiffInMSec = ((float) (endTimeNSec - startTimeNSec) / 1000000.0f) * 1000;
    printf("Total operations and time sorting by recursion merge sort: %d op., %f ms\n", operationCounter, timeDiffInMSec);

    //puts("Array after sort");
    //printArray(testArray, arraySize);

    puts("\nGoodbye!");

    return result;
}
