/**
 * Data structures: stack, queue
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"
#include "structures.h"

void queueDemo();
void convertInfixExpressionToPostfix();

int main(int argc, const char* argv[])
{
    // Queue task demo
    queueDemo();

    int i;
    int maxListSize = 100;
    int arrayListFromForPrint[maxListSize];
    int arrayListToForPrint[maxListSize];

    SingleLinkedList listFrom = createNewSingleLinkedList(maxListSize);
    SingleLinkedList listTo = createNewSingleLinkedList(maxListSize);

    // Fill single linked list
    for (i = 0; i < maxListSize; i++) {
        listFrom.add(&listFrom, i + 1);
    }

    // Convert listFrom to array and print
    printf("\nArray copy FROM before coping:\n");
    listFrom.toArray(&listFrom, arrayListFromForPrint);
    printArray((int*) arrayListFromForPrint, maxListSize);

    // Copy one single linked list to another
    listFrom.copy(&listFrom, &listTo);

    // Convert listTo to array and print
    printf("\nArray copy TO after coping:\n");
    listTo.toArray(&listTo, arrayListToForPrint);
    printArray((int*) arrayListToForPrint, maxListSize);

    // Do conversion
    convertInfixExpressionToPostfix();

    return 0;
}

/**
 * Демонстрация работы очереди
 */
void queueDemo()
{
    int maxQueueSize = 100;

    Queue queue = createNewQueue(maxQueueSize);

    int i;
    int value;
    int testValuesCount = 10;

    printf("\nEnqueue values ordered from %d to %d: ", 1, testValuesCount);
    for (i = 0; i < testValuesCount; i++) {
        printf("%3d", i + 1);
        queue.enqueue(&queue, i + 1);
    }

    printf("\nQueue size: %d\n", queue.size);

    printf("Dequeue values: ");
    for (i = 0; i < testValuesCount; i++) {
        value = queue.dequeue(&queue);
        printf("%d  ", value);
    }

    printf("\nQueue size: %d\n", queue.size);
}

void convertInfixExpressionToPostfix()
{
    int i, j, val1, val2, val3;
    int maxSize = 100;
    char token[10];

    char output[100] = "";
    char signs[5] = " +-*/";
    char sign;

    // Выражение должно разделяться пробелами (по одному пробелу между лексемами),
    // выражения в скобках не рассматриваются
    char bufInput[100] = "20 - 30 * 10"; // 20 30 - 10 *

    printf("\nInput expression: %s\n", bufInput);

    Queue queueOperands = createNewQueue(maxSize);
    Queue queueOperations = createNewQueue(maxSize);

    int strBufLength = strlen(bufInput);

    if (strBufLength < 5) {
        printf("Wrong expression format.\n");

        return;
    }

    for (i = 0; i < strBufLength; i++) {
        j = 0;
        while (bufInput[i] != ' ' && bufInput[i] != '\0') {
            token[j] = bufInput[i];
            j++, i++;
        }

        token[j] = '\0';

        if (isNumber(token)) {
            // Если встретили число, то кладем его в стек
            queueOperands.enqueue(&queueOperands, atoi(token));

            continue;
        }

        switch (token[0]) {
            case '+':
                queueOperations.enqueue(&queueOperations, 1);
                break;

            case '-':
                queueOperations.enqueue(&queueOperations, 2);
                break;

            case '*':
                queueOperations.enqueue(&queueOperations, 3);
                break;

            case '/':
                queueOperations.enqueue(&queueOperations, 4);
                break;

            default:
                printf("Wrong expression format.\n");
                return;
        }
    }

    while (queueOperands.size > 0) {
        val1 = queueOperands.dequeue(&queueOperands);
        val3 = queueOperations.dequeue(&queueOperations);

        sign = signs[val3];

        if (queueOperands.size >0) {
            val2 = queueOperands.dequeue(&queueOperands);

            sprintf(output, "%s %d %d %c", output, val1, val2, sign);
        } else {
            sprintf(output, "%s %d %c", output, val1, sign);
        }
    }

    printf("Result output expression: %s\n", output);
}
