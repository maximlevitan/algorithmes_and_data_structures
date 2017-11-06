/**
 * Dynamic programming
 *
 * Task 3
 *
 * Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по одному разу.
 * Здесь алгоритм решения такой же как и в задаче о 8 ферзях.
 * Разница только в проверке положения коня.
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tasks.h"
#include "helpers.h"
#include "dynamic.h"

int task3()
{
    int keyExite = 0;
    int N = 8;
    int M = 8;

    int board[8][8];

    do {
        puts("Chess horse traversal filling board.");

        fill2DArrayIntByValue((int*) board, N, M, 0);

        SearchSolution((int*) board, N, M, 1, 0, 0);

        puts("\nResult:");
        print2DArray((int*) board, N, M);

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
