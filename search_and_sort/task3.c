/**
 * Task 3
 *
 * Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив.
 * Функция возвращает индекс найденного элемента или -1, если элемент не найден.
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>

#include "tasks.h"
#include "helpers.h"
#include "search.h"

int task3()
{
    int keyExite = 0;

    int maxN = 100;
    int N = 0;
    int searchValue = 0;
    int operationCounter = 0;
    int foundIndex = 0;

    int inputData[maxN];
    for (int i = 0; i < maxN; i++) {
        inputData[i] = 0;
    }

    do {
        puts("Set input data for search integer value in sorted array.");

        printf("Input N(1..%i):", maxN);
        if (scanf("%d", &N) < 1) {
            return 1;
        }

        if (N < 1 || N > maxN) {
            printf("Wrong N, try again.");
            continue;
        }

        fillArrayIntDataFromInput(inputData, N);

        puts("Inserted array data:");
        printArray(inputData, N);

        printf("Input search integer value:");
        if (scanf("%d", &searchValue) < 1) {
            return 1;
        }

        operationCounter = 0;
        foundIndex = binarySearchInt(searchValue, inputData, N, &operationCounter);

        if (foundIndex > -1) {
            printf("Found index: %d\n", foundIndex);
        } else {
            puts("Searched index not found.");
        }

        printf("Total operations count: %d\n", operationCounter);

        printf("Try again? [1 or 0]:");
        if (scanf("%d", &keyExite) < 1) {
            return 1;
        }

        if (keyExite != 0) {
            continue;
        }

        puts("");

        break;
    } while (1);

    return 0;
}
