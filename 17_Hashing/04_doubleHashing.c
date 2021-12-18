#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int hash1(int key)
{
    return key % 10;
}

int hash2(int key)
{
    int r = 7; // nearest prime number to the size of the table;
    return r - (key % r);
}

int probe(int h[], int key)
{
    int index = hash1(key);
    int i = 0;
    while (h[(index + i * hash2(key)) % SIZE] != 0)
        i++;
    return (index + i * hash2(key)) % SIZE;
}

int search(int h[], int key)
{
    int index = hash1(key);
    int i = 0;
    while (h[(index + i * hash2(key)) % SIZE] != key)
    {
        i++;
        if (h[(index + i * hash2(key)) % SIZE] == 0)
        {
            return -1;
        }
    }
    return (index + i * hash2(key)) % SIZE;
}

void insert(int h[], int key)
{
    int index = hash1(key);

    if (h[index] != 0)
        index = probe(h, key);
    h[index] = key;
}

int main()
{
    int HT[SIZE] = {0};

    insert(HT, 5);
    insert(HT, 25);
    insert(HT, 15);
    insert(HT, 35);
    insert(HT, 92);

    printf("Key is present at index: %d\n", search(HT, 35));
}