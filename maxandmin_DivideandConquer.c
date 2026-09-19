#include<stdio.h>
struct Result{
    int max,min;
};
struct Result maxmin(int arr[], int low, int high){
    struct Result result,left,right;
    if(low==high){
        result.max=arr[low];
        result.min=arr[low];
        return result;
    }
    if(high==low+1){
        if(arr[low]>arr[high]){
            result.max=arr[low];
            result.min=arr[high];
        }
        else{
            result.max=arr[high];
            result.min=arr[low];
        }
        return result;
    }
    int mid=(low+high)/2;
    left=maxmin(arr,low,mid);
    right=maxmin(arr,mid+1,high);
    result.max=(left.max>right.max)?left.max:right.max;
    result.min=(left.min<right.min)?left.min:right.min;
    return result;
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
struct Result res=maxmin(arr,0,n-1);
printf("Maximum element: %d\n",res.max);
printf("Minimum element: %d\n",res.min);
return 0;
}