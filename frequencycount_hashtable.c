#include <stdio.h>
#define SIZE 100
int hashTable[SIZE];
int frequency[SIZE];
int hash(int key)
{
    if (key < 0)
        key = -key;
    return key % SIZE;
}
void insert(int key)
{
    int index = hash(key);
    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            frequency[index]++;
            return;
        }
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
    frequency[index] = 1;
}
int main()
{
    int a[100];
    int n, i;
    for (i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
        frequency[i] = 0;
    }
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    printf("\nFrequency of every distinct element:\n");
    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] != -1)
        {
            printf("%d -> %d\n",
                   hashTable[i], frequency[i]);
        }
    }
    return 0;
}