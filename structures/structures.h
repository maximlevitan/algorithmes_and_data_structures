#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

#ifndef ERROR_COLLECTION_SIZE
#define ERROR_COLLECTION_SIZE   "Can`t add new value: achieved max nodes collection size."
#endif // ERROR_COLLECTION_SIZE

#ifndef ERROR_NODE_MALLOC
#define ERROR_NODE_MALLOC "Can`t add new value: impossible to allocate some dynamic memory for new node."
#endif // ERROR_NODE_MALLOC

#define T_NULL 0

typedef int T;

// Node
typedef struct Node Node;

struct Node
{
    T value;
    Node* next;
};

// Queue
typedef struct Queue Queue;

struct Queue
{
    Node* head;
    Node* tail;

    int size;
    int maxSize;

    char* lastError;
    int hasError;

    void (*enqueue)(Queue*, T);

    T (*dequeue)(Queue*);
};

void enqueueNodeValue(Queue* queue, T value);

T dequeueNodeValue(Queue* queue);

Queue createNewQueue(int maxSize);

// Single Linked List
typedef struct SingleLinkedList SingleLinkedList;

struct SingleLinkedList
{
    Node* head;
    Node* tail;

    int size;
    int maxSize;

    char* lastError;
    int hasError;

    void (*add)(SingleLinkedList*, T);
    void (*toArray)(SingleLinkedList*, T*);
    void (*copy)(SingleLinkedList*, SingleLinkedList*);
};

void singleListAdd(SingleLinkedList* list, T value);

void singleListToArray(SingleLinkedList* list, T* resultArray);

void copySingleLinkedList(SingleLinkedList* from, SingleLinkedList* to);

SingleLinkedList createNewSingleLinkedList(int maxSize);

#endif // STRUCTURES_H_INCLUDED
