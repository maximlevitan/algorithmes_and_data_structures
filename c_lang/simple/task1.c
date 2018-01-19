/**
 * Task 1
 *
 * Ввести вес и рост человека.
 * Рассчитать и вывести индекс массы тела по формуле I=m/(h*h);
 * где m-масса тела в килограммах, h - рост в метрах.
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>

#include "simple_tasks.h"

int task1()
{
    int keyExite = 0;
    int mass = 0;
    float height = 0.0;
    float result = 0.0;

    do {
        printf("Enter human mass (kg.):");

        if (scanf("%d", &mass) < 1) {
            printf(_SIMPLE_TASKS_ARGUMENT_TYPE_ERROR);
            return 1;
        }

        if (mass < 0 || mass > 1000) {
            printf("Mass value must be from range: 1 - 1000, try again...\n");
            continue;
        }

        printf("Enter human height (meters):");

        if (scanf("%f", &height) < 1) {
            printf(_SIMPLE_TASKS_ARGUMENT_TYPE_ERROR);
            return 1;
        }

        if (height < 0.3 || height > 3.0) {
            printf("Height value must be from range: 0.3 - 3.0, try again...\n");
            continue;
        }

        result = mass / (height * height);

        printf("Calculated index result: %f\n", result);

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
