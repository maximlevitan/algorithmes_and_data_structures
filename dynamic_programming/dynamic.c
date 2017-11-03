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

int SearchSolution(int* board, int N, int M, int step)
{
    // Если проверка доски возвращает 0, то эта расстановка не подходит
    if (CheckBoard(board, N, M) == 0) {
        return 0;
    }

    // 65 ход коня уже не делаем. Решение найдено
    if (step > N * M) {
        return 1;
    }

    int row;
    int col;

    for (row = 0; row < N; row++) {
        for (col = 0; col < M; col++) {
            if (*(board + row * M + col) == 0) {
                // Расширяем CheckBoard
                *(board + row * M + col) = step;

                // Рекурсивно проверяем, ведет ли это к решению.
                if (SearchSolution(board, N, M, step + 1)) {
                    return 1;
                }

                // Если мы дошли до этой строки, данное частичное решение
                // не приводит к полному.
                *(board + row * M + col) = 0;
            }
        }
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
