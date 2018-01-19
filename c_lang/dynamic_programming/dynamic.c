/**
 * Dynamic programming algorithms
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>
#include <math.h>

#include "dynamic.h"

/**
 * W(a, b) = W(a, b − 1) + W(a − 1, b), a > 0, b > 0, map(a,b) = 1;
 * W(0, b) = 1, map(a,b) = 0;
 * W(a, 0) = 1, map(a,b) = 0;
 */
void countRoutsOfKingWithBarriers(
  int* result2dArray,
  int* barriers2dMap,
  int rowCount,
  int colCount
) {
    int j, i, deltaIdx;

    for (j = 0; j < colCount; j++) {
        *(result2dArray + j) = *(barriers2dMap + j) ? 1 : 0;
    }

    for(i = 1; i < rowCount; i++) {
        deltaIdx = i * colCount;
        *(result2dArray + deltaIdx) = *(barriers2dMap + deltaIdx) ? 1 : 0;

        for (j = 1; j < colCount; j++) {

            *(result2dArray + deltaIdx + j) = *(barriers2dMap + deltaIdx + j)
                ? (*(result2dArray + deltaIdx + j - 1) + *(result2dArray + deltaIdx - colCount + j))
                : 0;
        }
    }
}

int SearchSolution(int* board, int N, int M, int step, int x, int y)
{
    int row = y;
    int col = x;

    if (step > N * M) {
        return 1;
    }

    if (step == 1) {
        if (row < 0 || row >= N || col < 0 || col >= M) {
            return 0;
        }

        *(board + row * M + col) = step;

        // Рекурсивно проверяем, ведет ли это к решению.
        if (SearchSolution(board, N, M, step + 1, row, col)) {
            return 1;
        }

        // Если мы дошли до этой строки, данное частичное решение
        // не приводит к полному.
        *(board + row * M + col) = 0;
    }

    int caseNumber = 0;

    for (caseNumber = 0; caseNumber < 8; caseNumber++) {
        if (caseNumber == 0 && *(board + (row + 1) * M + col + 2) == 0 && row + 1 < N && col + 2 < M) {
            row += 1;
            col += 2;
        }

        if (caseNumber == 1 && *(board + (row + 2) * M + col + 1) == 0 && row + 2 < N && col + 1 < M) {
            row += 2;
            col += 1;
        }

        if (caseNumber == 2 && *(board + (row + 2) * M + col - 1) == 0 && row + 2 < N && col - 1 >= 0) {
            row += 2;
            col -= 1;
        }

        if (caseNumber == 3 && *(board + (row + 1) * M + col - 2) == 0 && row + 1 < N && col - 2 >= 0) {
            row += 1;
            col -= 2;
        }

        if (caseNumber == 4 && *(board + (row - 1) * M + col - 2) == 0 && row - 1 >= 0 && col - 2 >= 0) {
            row -= 1;
            col -= 2;
        }

        if (caseNumber == 5 && *(board + (row - 2) * M + col - 1) == 0 && row - 2 >= 0 && col - 1 >= 0) {
            row -= 2;
            col -= 1;
        }

        if (caseNumber == 6 && *(board + (row - 2) * M + col + 1) == 0 && row - 2 >= 0 && col + 1 < M) {
            row -= 2;
            col += 1;
        }

        if (caseNumber == 7 && *(board + (row - 1) * M + col + 2) == 0 && row - 1 >= 0 && col + 2 < M) {
            row -= 1;
            col += 2;
        }

        if (row == x || row == y || row < 0 || row >= N || col < 0 || col >= M) {
            continue;
        }

        *(board + row * M + col) = step;

        // Рекурсивно проверяем, ведет ли это к решению.
        if (SearchSolution(board, N, M, step + 1, row, col)) {
            return 1;
        }

        // Если мы дошли до этой строки, данное частичное решение
        // не приводит к полному.
        *(board + row * M + col) = 0;
    }

    return 0;
}

// Проверка всей доски
int CheckBoard(int* board, int N, int M)
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (*(board + i * M + j) != 0) {
                if (CheckHorse(board, N, M, i, j) == 0) {
                    return  0;
                }
            }
        }
    }

    return 1;
}

int CheckHorse(int* board, int N, int M, int x, int y)
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            // Если нашли  фигуру
            if (*(board + i * M + j) != 0) {
                if (i == x && j == y) { // Если это наша фигура
                    continue;
                }

                // Лежит на пути коня
                if (abs(i - x) == 1 && abs(j - y) == 2
                    || abs(i - x) == 2 && abs(j - y) == 1
                ) {
                    return 0;
                }
            }
        }
    }

    // Если дошли до сюда, то всё в порядке

    return 1;
}
