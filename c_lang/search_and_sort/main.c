/**
 * Search and sort
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>

#include "tasks.h"

#define ARGUMENT_TYPE_ERROR "\nERROR: unexpected input argument type or empty value.\n"

void showMenu();
int appControlLoop();
void printError(int code);

int main(int argc, const char* argv[])
{
    int resultCode = appControlLoop();
    if (resultCode) {
        printError(resultCode);

        return resultCode;
    }

    puts("Goodbye!");

    return 0;
}

int appControlLoop()
{
    int resultCode = 0;
    int selectedTaskId = 0;

    do {
        showMenu();

        printf("Enter task number [1-3] or 0 for exit:");

        if (scanf("%d", &selectedTaskId) < 1) {
            resultCode = 1;
            break;
        }

        switch (selectedTaskId) {
            case 0:
                break;
            case 1:
                resultCode = task1();
                break;
            case 2:
                resultCode = task2();
                break;
            case 3:
                resultCode = task3();
                break;
            default:
                resultCode = 2;
        }

        if (resultCode) {
            break;
        }
    } while (selectedTaskId != 0);

    return resultCode;
}

void showMenu()
{
    printf("\nSelect task number:\n");
    printf("1 - run task 1\n");
    printf("2 - run task 2\n");
    printf("3 - run task 3\n");
    printf("0 - exit\n");
}

void printError(int code)
{
    switch (code) {
        case 1:
            printf(ARGUMENT_TYPE_ERROR);
            break;
        case 2:
            printf("Unexisting task number\n");
            break;
        default:
            break;
    }
}
