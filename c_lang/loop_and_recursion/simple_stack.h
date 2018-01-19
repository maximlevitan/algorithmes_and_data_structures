#ifndef SIMPLE_STACK_H_INCLUDED
#define SIMPLE_STACK_H_INCLUDED

#define DEFAULT_SIMPLE_STACK_MAX_SIZE 100

typedef struct SimpleNodeOfInteger IntSimpleNode;
typedef struct SimpleStackOfInteger IntSimpleStack;

struct SimpleNodeOfInteger {
    int data;

    IntSimpleNode* next;
};

struct SimpleStackOfInteger {
    IntSimpleNode* top;

    int size;
    int maxSize;

    char* lastError;
    int hasError;

    int (*pop)(IntSimpleStack*);

    void (*push)(IntSimpleStack*, int);

    int (*peek)(IntSimpleStack*);
};

int simpleStackPop(IntSimpleStack* stack);

void simpleStackPush(IntSimpleStack* stack, int value);

int simpleStackPeek(IntSimpleStack* stack);

IntSimpleStack createNewSimpleStack(int maxStackSize);

#endif // SIMPLE_STACK_H_INCLUDED
