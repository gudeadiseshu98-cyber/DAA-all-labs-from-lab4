#include<stdio.h>
struct item{
    int weight;
    int profit;
    float ratio;
};
int main(){
    int n;
    printf("Enter number of items: ");
    scanf("%d",&n);
    struct item items[n];
    printf("Enter weight and profit of each item:\n");
    for(int i=0;i<n;i++){
        scanf("%d %d",&items[i].weight,&items[i].profit);
        items[i].ratio=(float)items[i].profit/items[i].weight;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(items[j].ratio<items[j+1].ratio){
                struct item temp=items[j];
                items[j]=items[j+1];
                items[j+1]=temp;
            }
        }
    }
    int capacity;
    printf("Enter capacity of knapsack: ");
    scanf("%d",&capacity);
    float total_profit=0;
    for(int i=0;i<n;i++){
        if(items[i].weight<=capacity){
            total_profit+=items[i].profit;
            capacity-=items[i].weight;
        }
        else{
            total_profit+=items[i].ratio*capacity;
            capacity=0;
            break;
        }
    }
    printf("Maximum profit: %.2f\n",total_profit);
    return 0;
}
