/**
 * Task 13
 *
 * Написать функцию, генерирующую случайное число от 1 до 100:
 * - с использованием стандартной функции rand()
 * - без использования стандартной функции rand()
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "simple_tasks.h"

int getOwnRand();
int randNumber(int min, int max, int useStdRand);

int task13()
{
    int keyExite = 0;
    int rangeFrom = 1;
    int rangeTo = 100;

    srand((unsigned) time(NULL));

    do {
        printf("Random value using stdlib rand function: %d\n", randNumber(rangeFrom, rangeTo, 1));
        printf("Random value using own rand function: %d\n", randNumber(rangeFrom, rangeTo, 0));

        printf("Try again? [1 or 0]:");

        if (scanf("%d", &keyExite) < 1) {
            printf(_SIMPLE_TASKS_ARGUMENT_TYPE_ERROR);
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

int randNumber(int min, int max, int useStdRand)
{
    return ((useStdRand > 0) ? rand() : getOwnRand()) % (max + 1 - min) + min;
}

int getOwnRand()
{
    static int currentX = 1;

    int multiplier = 11;
    int addend = 14;
    int mask = 1048576;

    currentX = (multiplier * currentX + addend) % mask;

    return currentX;
}
