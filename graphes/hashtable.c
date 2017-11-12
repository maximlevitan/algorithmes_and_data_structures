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

    hashTable.insert = &insertHashTableNode;

    return hashTable;
}

BSTree* insertHashTableNode(HashTable* hashTable, T value)
{
    HashTableIndex hash = hashCode(value);

    BSTree* tmpTree = hashTable->trees[hash];

    if (tmpTree == NULL) {
        BSTree newTree = createNewBSTree();

        hashTable->trees[hash] = &newTree;

        newTree.insert(&newTree, value);

        return &newTree;
    }

    tmpTree->insert(tmpTree, value);

    return tmpTree;
}
