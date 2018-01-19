/**
 * Task 2
 *
 * Найти максимальное из четырех чисел. Массивы не использовать.
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>

#include "simple_tasks.h"

int task2()
{

    int keyExite = 0;
    int value1 = 0;
    int value2 = 0;
    int value3 = 0;
    int value4 = 0;
    int maxValue = 0;

    do {
        printf("Enter 1st integer value:");

        if (scanf("%d", &value1) < 1) {
            printf(_SIMPLE_TASKS_ARGUMENT_TYPE_ERROR);
            return 1;
        }

        printf("Enter 2nd integer value:");
        if (scanf("%d", &value2) < 1) {
            printf(_SIMPLE_TASKS_ARGUMENT_TYPE_ERROR);
            return 1;
        }

        printf("Enter 3rd integer value:");
        if (scanf("%d", &value3) < 1) {
            printf(_SIMPLE_TASKS_ARGUMENT_TYPE_ERROR);
            return 1;
        }

        printf("Enter 4th integer value:");
        if (scanf("%d", &value4) < 1) {
            printf(_SIMPLE_TASKS_ARGUMENT_TYPE_ERROR);
            return 1;
        }

        maxValue = value1;
        maxValue = (maxValue > value2) ? maxValue : value2;
        maxValue = (maxValue > value3) ? maxValue : value3;
        maxValue = (maxValue > value4) ? maxValue : value4;

        printf("Max value: %d\n", maxValue);

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
