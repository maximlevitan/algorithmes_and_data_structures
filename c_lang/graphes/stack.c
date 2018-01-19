#include <stdio.h>
#include <stdlib.h>

#include "structures.h"

T stackPop(Stack* stack)
{
    T result = T_NULL;

    if (stack->top == NULL) {
        return result;
    }

    Node* next = stack->top;

    result = stack->top->value;

    stack->top = stack->top->next;
    free(next);
    stack->size--;

    return result;
}

void stackPush(Stack* stack, T value)
{
    stack->lastError = "";
    stack->hasError = 0;

    if (stack->size == stack->maxSize) {
        stack->lastError = ERROR_COLLECTION_SIZE;
        stack->hasError = 1;

        return;
    }

    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        stack->lastError = ERROR_NODE_MALLOC;
        stack->hasError = 1;

        return;
    }

    newNode->value = value;
    newNode->next = stack->top;

    stack->top = newNode;
    stack->size++;
}

T stackPeek(Stack* stack)
{
    return (stack->top != NULL) ? stack->top->value : T_NULL;
}

Stack createNewStack(int maxSize)
{
    Stack stack;

    stack.top = NULL;
    stack.size = 0;
    stack.maxSize = maxSize;

    stack.pop = &stackPop;
    stack.push = &stackPush;
    stack.peek = &stackPeek;

    return stack;
}
