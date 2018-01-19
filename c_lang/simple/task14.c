/**
 * Task 14
 *
 * Автоморфные числа.
 *
 * Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата.
 * Например: 25 * 25 = 625.
 *
 * Напишите программу, которая вводит натуральное число N и выводит на экран все автоморфные числа, не превосходящие N.
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>

#include "simple_tasks.h"

int task14()
{
    int keyExite = 0;
    int naturalLimitNumber = 0;

    do {
        do {
            printf("Enter natural integer number > 0:");

            if (scanf("%d", &naturalLimitNumber) < 1) {
                printf(_SIMPLE_TASKS_ARGUMENT_TYPE_ERROR);
                return 1;
            }

            if (naturalLimitNumber < 1) {
                printf("Wrong number.\n");
                continue;
            }

            break;
        } while (1);

        int i;
        int resultCounter = 0;
        int numberBase = 10;
        for (i = 1; i <= naturalLimitNumber; i++) {
            if (i == numberBase) {
                numberBase *= 10;
            }

            if (i == 1 || (i * i) % numberBase == i) {
                if (resultCounter > 0) {
                    printf(", %d", i);
                } else {
                    printf("Anamorph result numbers: %d", i);
                }

                resultCounter++;
            }
        }

        if (resultCounter > 0) {
            puts("");
        }


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
