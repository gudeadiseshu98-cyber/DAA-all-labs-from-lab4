#include<stdio.h>
/* Function to merge two subarrays */
void merge(int arr[], int l, int m, int r){
    int i=l, j=m+1, k=0;
    int temp[100];
    while(i <= m && j <= r){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i <= m){
        temp[k++] = arr[i++];
    }
    while(j <= r){
        temp[k++] = arr[j++];
    }
    // Copy the merged elements back to the original array
    for(i = l; i <= r; i++){
        arr[i] = temp[i - l];
    }
}
/* Merge Sort Function */
void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main(){
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    printf("Sorted array: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}