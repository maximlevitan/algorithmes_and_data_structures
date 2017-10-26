/**
 * Loops and recursion
 *
 * Исполнитель Калькулятор преобразует целое число, записанное на экране.
 * У исполнителя две команды, каждой команде присвоен номер:
 * 1. Прибавь 1
 * 2. Умножь на 2
 *
 * Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза.
 * Сколько существует программ, которые число 3 преобразуют в число 20.
 *  - с использованием массива (сделал с использованием цикла, стека и массива результатов);
 *  - с использованием рекурсии.
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>

#include "task_menu.h"
#include "simple_stack.h"

#define ARGUMENT_TYPE_ERROR "\nERROR: unexpected input argument type or empty value.\n"

int executeTask(int type);
void loopSolution(int startValue, int endValue, int* resultData);
void recursionSolution(int startValue, int endValue, int* resultData);

int main(int argc, const char* argv[])
{
    int selectedTaskId = 0;

    do {
        showMenu();

        printf("Enter task number [1, 2] or 0 for exit:");

        if (scanf("%d", &selectedTaskId) < 1) {
            printf(ARGUMENT_TYPE_ERROR);
            return 1;
        }

        switch (selectedTaskId) {
            case 0:
                break;
            case 1:
                executeTask(1);
                break;
            case 2:
                executeTask(2);
                break;
            default:
                printf("Unexisting task number\n");
        }
    } while (selectedTaskId != 0);

    puts("Goodbye!");

    return 0;
}

int executeTask(int type)
{
    int keyExite = 0;
    int startValue = 0;
    int endValue = 0;

    int i;

    do {
        printf("Enter start value:");

        if (scanf("%d", &startValue) < 1) {
            printf(ARGUMENT_TYPE_ERROR);
            return 1;
        }

        if (startValue < 0) {
            printf("Wrong value\n");
            continue;
        }

        printf("Enter end value:");

        if (scanf("%d", &endValue) < 1) {
            printf(ARGUMENT_TYPE_ERROR);
            return 1;
        }

        if (endValue < 0 || endValue < startValue) {
            printf("Wrong value\n");
            continue;
        }

        // Подготовили пустой массив для записи счетчиков путей достижения каждого числа из интревала
        int* resultData = malloc((endValue + 1) * sizeof(int));
        for (i = 0; i < endValue + 1; i++) {
            resultData[i] = 0;
        }

        if (type == 1) {
            loopSolution(startValue, endValue, resultData);
        } else if (type == 2) {
            recursionSolution(startValue, endValue, resultData);
        } else {
            free(resultData);
            break;
        }

        printf("Counted results:\n");

        for (i = 0; i < endValue + 1; i++) {
            printf("Value %d calculations paths count: %d\n", i, resultData[i]);
        }

        free(resultData);

        printf("Try again? [1 or 0]:");

        if (scanf("%d", &keyExite) < 1) {
            printf(ARGUMENT_TYPE_ERROR);
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

void loopSolution(int startValue, int endValue, int* resultData)
{
    if (startValue == endValue) {
        return;
    }

    int nodeValue = startValue;

    IntSimpleStack stack = createNewSimpleStack(endValue - startValue + 1);
    stack.push(&stack, nodeValue);

    while (1) {
        // Идем по левой ветви дерева вниз до последнего элемента, пока не достигли endValue
        while (nodeValue < endValue) {
            nodeValue++;
            resultData[nodeValue]++;

            stack.push(&stack, nodeValue);
        }

        // Увеличиваем счетчик способов достижения endValue
        if (nodeValue == endValue) {
            resultData[nodeValue]++;

            nodeValue = stack.pop(&stack);
        }

        // Поднимаемся вверх по дереву
        while (nodeValue * 2 > endValue) {
            nodeValue = stack.pop(&stack);
        }

        if (nodeValue * 2 == endValue) {
            resultData[nodeValue]++;

            nodeValue = stack.pop(&stack);
        }

        if (nodeValue == 0) {
            break;
        }

        nodeValue *= 2;
        resultData[nodeValue]++;

        stack.push(&stack, nodeValue);
    }
}

void recursionSolution(int startValue, int endValue, int* resultData)
{
    resultData[startValue]++;

    if (startValue + 1 > endValue) {
        return;
    }

    recursionSolution(startValue + 1, endValue, resultData);

    if (startValue * 2 > endValue) {
        return;
    }

    recursionSolution(startValue * 2, endValue, resultData);
}
