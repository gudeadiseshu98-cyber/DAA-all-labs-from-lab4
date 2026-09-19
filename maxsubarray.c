#include<stdio.h>
#include<limits.h>
int max(int a, int b){
    return (a > b) ? a : b;
}
int crosssum(int arr[], int low, int mid, int high){
    int left_sum=INT_MIN;
    int right_sum=INT_MIN;
    int sum=0;
    for(int i=mid;i>=low;i--){
        sum+=arr[i];
        if(sum>left_sum){
            left_sum=sum;
        }
    }
    sum=0;
    for(int i=mid+1;i<=high;i++){
        sum+=arr[i];
        if(sum>right_sum){
            right_sum=sum;
        }
    }
    return left_sum+right_sum;
}
int maxsubarray(int arr[],int low,int high){
    if(low==high){
        return arr[low];
    }
    int mid=(low+high)/2;
    int left_sum=maxsubarray(arr,low,mid);
    int right_sum=maxsubarray(arr,mid+1,high);
    int cross_sum=crosssum(arr,low,mid,high);
    return max(max(left_sum,right_sum),cross_sum);
}
int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int max_sum=maxsubarray(arr,0,n-1);
    printf("Maximum subarray sum: %d\n",max_sum);
    return 0;
}