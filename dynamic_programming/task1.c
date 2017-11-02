/**
 * Dynamic programming
 *
 * Task 1
 *
 * Количество маршрутов с препятствиями.
 * Реализовать чтение массива с препятствием и нахождение количество маршрутов.
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>

#include "tasks.h"
#include "helpers.h"
#include "dynamic.h"

void prepareRandomBarriers(int* barriersMap, int rowCount, int colCount, int barrierCount);

int task1()
{
    int keyExite = 0;
    int maxN = 100;
    int maxM = 100;
    int N = 0;
    int M = 0;

    int barriersMap[maxN][maxM];
    int resultData[maxN][maxM];

    do {
        fill2DArrayIntByValue((int*) barriersMap, maxN, maxM, 1);

        printf("Input N(1..%i):", maxN);
        if (scanf("%d", &N) < 1) {
            return 1;
        }

        if (N < 3 || N > maxN) {
            printf("Wrong N, needs 3 < N < 100, try again.");
            continue;
        }

        printf("Input M(1..%i):", maxM);
        if (scanf("%d", &M) < 1) {
            return 1;
        }

        if (M < 3 || M > maxM) {
            printf("Wrong M, needs 3 < M < 100, try again.");
            continue;
        }

        //prepareRandomBarriers((int*) barriersMap, N, M, N);

        puts("Prepared barriers map:");
        print2DArray((int*) barriersMap, N, M);

        countRoutsOfKingWithBarriers((int*) resultData, (int*) barriersMap, N, M);

        puts("Result calculation of chess king routes with barrier map:");
        print2DArray((int*) resultData, N, M);

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

void prepareRandomBarriers(int* barriersMap, int rowCount, int colCount, int barrierCount)
{
    int minRand = 1;
    int maxRand = (rowCount - 1) * (colCount - 1);
    int randomIndex = minRand;

    for (int i = 0; i < barrierCount; i++) {
        randomIndex = randNumber(minRand, maxRand);

        *(barriersMap + randomIndex) = 0;
    }
}
