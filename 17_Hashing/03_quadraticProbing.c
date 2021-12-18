#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int hash(int key)
{
    return key % 10;
}

int probe(int h[], int key)
{
    int index = hash(key);
    int i = 0;
    while (h[(index + i * i) % SIZE] != 0)
        i++;
    return (index + i * i) % SIZE;
}

int search(int h[], int key)
{
    int index = hash(key);
    int i = 0;
    while (h[(index + i * i) % SIZE] != key)
    {
        i++;
        if (h[(index + i * i) % SIZE] == 0)
        {
            return -1;
        }
    }
    return (index + i * i) % SIZE;
}

void insert(int h[], int key)
{
    int index = hash(key);

    if (h[index] != 0)
        index = probe(h, key);
    h[index] = key;
}

int main()
{
    int HT[SIZE] = {0};

    insert(HT, 13);
    insert(HT, 15);
    insert(HT, 25);
    insert(HT, 35);
    insert(HT, 12);

    printf("Key is present at index: %d\n", search(HT, 35));
}