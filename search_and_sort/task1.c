/**
 * Task 1
 *
 * Попробовать оптимизировать пузырьковую сортировку.
 * Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.
 * Написать функции сортировки, которые возвращают количество операций.
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>

#include "tasks.h"
#include "helpers.h"
#include "sort.h"

int task1()
{
    int keyExite = 0;
    int maxN = 100;
    int N = 0;
    int operationCounter = 0;

    int inputData[maxN];
    for (int i = 0; i < maxN; i++) {
        inputData[i] = 0;
    }

    do {
        printf("Input N(1..%i):", maxN);
        if (scanf("%d", &N) < 1) {
            return 1;
        }

        if (N < 1 || N > maxN) {
            printf("Wrong N, try again.");
            continue;
        }

        fillArrayIntDataFromInput(inputData, N);

        puts("Array before sort");
        printArray(inputData, N);

        operationCounter = 0;
        //bubbleSortInt(inputData, N, &operationCounter);
        boostedBubbleSortInt(inputData, N, &operationCounter);

        puts("Array after sort");
        printArray(inputData, N);

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
