#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];
int hash(int key)
{
    return key % SIZE;
}
void insert(int key)
{
    int index;
    int i = 0;
    index = hash(key);
    while (hashTable[index] != -1 && i < SIZE)
    {
        i++;
        index = (hash(key) + i * i) % SIZE;
    }
    if (i < SIZE)
        hashTable[index] = key;
    else
        printf("Hash table is full!\n");
}
void display()
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
            printf("%d : Empty\n", i);
        else
            printf("%d : %d\n", i, hashTable[i]);
    }
}
int main()
{
    int n, key, i;
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }
    printf("\nHash Table:\n");
    display();
    return 0;
}