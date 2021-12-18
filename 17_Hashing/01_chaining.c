#include <stdio.h>
#include <stdlib.h>
#include "chaining.h"

int hash(int n)
{
    return n % 10;
}

void createChain(struct Node *h[], int n)
{
    int index = hash(n);
    sortedInsert(&h[index], n);
}

struct Node *searchChain(struct Node *HT[], int key)
{
    struct Node *temp = search(HT[hash(key)], key);
    return temp;
}

int main()
{
    struct Node *HT[10];
    struct Node *temp;

    int i;
    for (i = 0; i < 10; i++)
        HT[i] = NULL;

    int key = 45;

    createChain(HT, 10);
    createChain(HT, 5);
    createChain(HT, 15);
    createChain(HT, 2);
    createChain(HT, key);

    searchChain(HT, key) ? printf("%d Found\n", key) : printf("%d Not found\n", key);

    deleteNode(HT[hash(key)], key);

    searchChain(HT, key) ? printf("%d Found\n", key) : printf("%d Not found\n", key);
}