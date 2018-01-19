/**
 * Task 3
 *
 * Написать программу обмена значениями двух целочисленных переменных
 * без использования третьей переменной.
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>

#include "simple_tasks.h"

int task3()
{
    int keyExite = 0;
    int value1 = 0;
    int value2 = 0;

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

        // value1 = 4 = 100(2), value2 = 5 = 101(5);
        value2 = value1^value2; // 001 = 100 ^ 101;
        value1 = value1^value2; // 101 = 100 ^ 001;
        value2 = value1^value2; // 100 = 101 ^ 001

        printf("Changed 1st value: %d, changed 2nd value: %d\n", value1, value2);

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
