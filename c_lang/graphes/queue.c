#include <stdio.h>
#include <stdlib.h>

#include "structures.h"

Queue createNewQueue(int maxSize)
{
    Queue queue;

    queue.head = NULL;
    queue.tail = NULL;
    queue.size = 0;
    queue.maxSize = maxSize;

    queue.enqueue = &enqueueNodeValue;
    queue.dequeue = &dequeueNodeValue;

    return queue;
}

void enqueueNodeValue(Queue* queue, T value)
{
    queue->lastError = "";
    queue->hasError = 0;

    if (queue->size == queue->maxSize) {
        queue->lastError = ERROR_COLLECTION_SIZE;
        queue->hasError = 1;

        return;
    }

    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        queue->lastError = ERROR_NODE_MALLOC;
        queue->hasError = 1;

        return;
    }

    newNode->value = value;
    newNode->next = NULL;

    if (queue->head == NULL) {
        queue->head = newNode;
        queue->tail = queue->head;
    } else {
        queue->tail->next = newNode;
        queue->tail = queue->tail->next;
    }

    queue->size++;
}

T dequeueNodeValue(Queue* queue)
{
    T result = T_NULL;

    if (queue->head == NULL) {
        queue->tail = NULL;

        return result;
    }

    Node* next = queue->head;

    result = queue->head->value;

    queue->head = queue->head->next;
    free(next);
    queue->size--;

    return result;
}
