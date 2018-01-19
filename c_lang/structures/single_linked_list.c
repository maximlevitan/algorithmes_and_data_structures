#include <stdio.h>
#include <stdlib.h>

#include "structures.h"

SingleLinkedList createNewSingleLinkedList(int maxSize)
{
    SingleLinkedList list;

    list.head = NULL;
    list.size = 0;
    list.maxSize = maxSize;


    list.add = &singleListAdd;
    list.toArray = &singleListToArray;
    list.copy = &copySingleLinkedList;

    return list;
}

void singleListAdd(SingleLinkedList* list, T value)
{
    list->lastError = "";
    list->hasError = 0;

    if (list->size == list->maxSize) {
        list->lastError = ERROR_COLLECTION_SIZE;
        list->hasError = 1;

        return;
    }

    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        list->lastError = ERROR_NODE_MALLOC;
        list->hasError = 1;

        return;
    }

    newNode->value = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = list->head;
    } else {
        list->tail->next = newNode;
        list->tail = list->tail->next;
    }

    list->size++;
}

void singleListToArray(SingleLinkedList* list, T* resultArray)
{
    if (list->size < 1) {
        return;
    }

    Node* current = list->head;
    while (current != NULL) {
        *(resultArray++) = current->value;
        current = current->next;
    }
}

void copySingleLinkedList(SingleLinkedList* from, SingleLinkedList* to)
{
    if (from->size < 1) {
        return;
    }

    Node* current = from->head;
    while (current != NULL) {
        to->add(to, current->value);

        current = current->next;
    }
}
