#include <stdio.h>
#define SIZE 100
int hashTable[SIZE];
int hash(int key)
{
    if (key < 0)
        key = -key;
    return key % SIZE;
}
int main()
{
    int a[100], n, T;
    int i, index, complement;
    int found = 0;
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter target T: ");
    scanf("%d", &T);
    for (i = 0; i < n; i++)
    {
        complement = T - a[i];
        index = hash(complement);
        if (hashTable[index] == complement)
        {
            printf("Pair found: %d + %d = %d\n",
                   complement, a[i], T);
            found = 1;
            break;
        }
        hashTable[hash(a[i])] = a[i];
    }
    if (!found)
        printf("No pair found\n");
    return 0;
}