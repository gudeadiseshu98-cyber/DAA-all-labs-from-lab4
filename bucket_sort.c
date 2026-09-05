#include<stdio.h>
void bucketsort(float a[],int n){
    int i,j,k;
    float b[n][n];
    int count[n];
    for(i=0;i<n;i++)
        count[i]=0;
    //filling the buckets
    for(i=0;i<n;i++){
        int index=a[i]*n;
        b[index][count[index]++]=a[i];
    }
    //printing the buckets
    for(i=0;i<n;i++){
        printf("Bucket %d: ",i);
        for(j=0;j<count[i];j++)
            printf("%.2f ",b[i][j]);
        printf("\n");
    }
    //sorting elements within each bucket
    for(i=0;i<n;i++){
        for(int j=0;j<count[i]-1;j++){
            for(k=j+1;k<count[i];k++){
                if(b[i][j]>b[i][k]){
                    float temp=b[i][j];
                    b[i][j]=b[i][k];
                    b[i][k]=temp;
                }
            }
        }
    }
    //merging the buckets
    int index=0;
    for(i=0;i<n;i++){
        for(j=0;j<count[i];j++){
            a[index++]=b[i][j];
        }
    }
}
int main(){
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    float a[n];
    printf("Enter the elements (between 0 and 1):\n");
    for(i=0;i<n;i++)
        scanf("%f",&a[i]);
    bucketsort(a,n);
    printf("Sorted array:\n");
    for(i=0;i<n;i++)
        printf("%.2f ",a[i]);
    return 0;
}