#include <stdio.h>
int quick(int arr[], int lb, int ub)
{
    int pivot = arr[lb],start = lb,end = ub,temp;
    while (start < end)
    {
        while (arr[start] <= pivot )
            start++;
        while (arr[end] > pivot)
            end--;
        if (start < end)
        {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;
    return end;
}
void quickSort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = quick(arr, lb, ub);
        quickSort(arr, lb, loc - 1);
        quickSort(arr, loc + 1, ub);
    }
}
int main()
{
    int arr[100], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    quickSort(arr, 0, n - 1);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}