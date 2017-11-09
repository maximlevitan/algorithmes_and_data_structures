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

// Stack
typedef struct Stack Stack;

struct Stack {
    Node* top;

    int size;
    int maxSize;

    char* lastError;
    int hasError;

    T (*pop)(Stack*);

    void (*push)(Stack*, T);

    T (*peek)(Stack*);
};

T stackPop(Stack* stack);

void stackPush(Stack* stack, T value);

T stackPeek(Stack* stack);

Stack createNewStack(int maxSize);

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

// TreeNode
typedef struct TreeNode TreeNode;

struct TreeNode
{
    T value;

    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
};

// BSTree
typedef struct BSTree BSTree;

struct BSTree
{
    TreeNode* root;

    int size;

    char* lastError;
    int hasError;

    void (*insert)(BSTree*, T*);
};

BSTree createNewBSTree();

TreeNode* getBSTreeFreeNode(BSTree* tree, T value, TreeNode* parent);

void insertBSTreeNode(BSTree* tree, T value);

void preOrderTraversalTreePrint(TreeNode* root);
void inOrderTraversalTreePrint(TreeNode* root);
void postOrderTraversalTreePrint(TreeNode* root);

void printTree(TreeNode* root);

// HashTable
typedef unsigned int HashTableIndex;

typedef struct HashTable HashTable;

struct HashTable
{
    BSTree** trees;

    int size;

    char* lastError;
    int hasError;

    BSTree* (*insert)(HashTable*, T*);
    //void (*delete)(HashTable*, T*);
    //void (*find)(HashTable*, T*);
};

HashTableIndex hashSumString(char* string);

HashTableIndex hashCode(T value);

HashTable createNewHashTable();

BSTree* insertHashTableNode(HashTable* hashTable, T value);

#endif // STRUCTURES_H_INCLUDED
