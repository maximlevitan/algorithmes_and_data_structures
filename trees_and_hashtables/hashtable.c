#include <stdio.h>
#include <stdlib.h>

#include "structures.h"

// Функция получает хэш строки суммируя коды символов
HashTableIndex hashSumString(char* string)
{
    HashTableIndex hash = 0;

    while (*string) {
        hash += *(string++);
    }

    return hash;
}

HashTableIndex hashCode(T value)
{
    return (value % 100);
}

HashTable createNewHashTable()
{
    HashTable hashTable;

    tree.insert = &insertHashTableNode;

    return tree;
}

BSTree* insertHashTableNode(HashTable* hashTable, T value)
{
    BSTree* treePtr1;
    BSTree* treePtr2;

    HashTableIndex hashCode = hashCode(value);

    *treePtr1 = createNewBSTree();

    treePtr2 = hashTable->trees[hashCode];

    hashTable->trees[hashCode] = treePtr1;

    treePtr1->insert(treePtr1, value);

    return treePtr1;
}
