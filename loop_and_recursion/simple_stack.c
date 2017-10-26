#include <stdio.h>
#include <stdlib.h>

#include "simple_stack.h"

int simpleStackPop(IntSimpleStack* stack)
{
    int result = 0;

    if (stack->top == NULL) {
        return result;
    }

    IntSimpleNode* currentTop = stack->top;
    stack->top = stack->top->next;
    stack->size--;

    result = currentTop->data;

    free(currentTop);

    return result;
}

void simpleStackPush(IntSimpleStack* stack, int value)
{
    char* errorMessage = "Can`t push new value: achieved max stack size.";
    stack->lastError = "";
    stack->hasError = 0;

    if (stack->size == stack->maxSize) {
        stack->lastError = errorMessage;
        stack->hasError = 1;

        return;
    }

    IntSimpleNode* newNode = malloc(sizeof(IntSimpleNode));

    newNode->data = value;
    newNode->next = stack->top;

    stack->top = newNode;
    stack->size++;
}

int simpleStackPeek(IntSimpleStack* stack)
{
    return (stack->top != NULL) ? stack->top->data : 0;
}

IntSimpleStack createNewSimpleStack(int maxStackSize)
{
    IntSimpleStack stack;

    stack.top = NULL;
    stack.size = 0;
    stack.maxSize = (maxStackSize > DEFAULT_SIMPLE_STACK_MAX_SIZE)
        ? maxStackSize : DEFAULT_SIMPLE_STACK_MAX_SIZE;

    stack.pop = &simpleStackPop;
    stack.push = &simpleStackPush;
    stack.peek = &simpleStackPeek;

    return stack;
}
