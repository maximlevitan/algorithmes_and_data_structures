/**
 * Data structures: stack, queue
 *
 * @author Maxim Levitan <maximlevitan@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"
#include "structures.h"

void queueDemo();

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
