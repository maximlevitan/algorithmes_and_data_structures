/**
 * Simple alghorithms
 *
 * Practice works by course of Alghorithms and Data Structures
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>

#include "task_menu.h"
#include "simple_tasks.h"

void executeTask1();

int main(int argc, const char* argv[])
{
    int selectedTaskId = 0;

    do {
        showMenu();

        printf("Enter task number [1-3, 13, 14] or 0 for exit:");

        if (scanf("%d", &selectedTaskId) < 1) {
            printf(_SIMPLE_TASKS_ARGUMENT_TYPE_ERROR);
            return 1;
        }

        switch (selectedTaskId) {
            case 0:
                break;
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 13:
                task13();
                break;
            case 14:
                task14();
                break;
            default:
                printf("Unexisting task number\n");
        }
    } while (selectedTaskId != 0);

    puts("Goodbye!");

    return 0;
}
