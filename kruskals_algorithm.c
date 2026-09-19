#include<stdio.h>
#define MAX 100
int parent[MAX];
struct edge{
    int weight,src,dest;
};
void sort(struct edge edges[],int e){
    int i,j;
    struct edge temp;
    for(i=0;i<e-1;i++){
        for(j=i+1;j<e;j++){
            if(edges[i].weight>edges[j].weight){
                temp=edges[i];
                edges[i]=edges[j];
                edges[j]=temp;
            }
        }
    }
}
int find(int x){
    while(parent[x]!=x){
        x=parent[x];
    }
    return x;
}
void union1(int x,int y){
    int a=find(x);
    int b=find(y);
    if(a!=b){
        parent[b]=a;
    }
}
int main(){
    int n,e,i;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d",&n,&e);
    struct edge edges[e];
    for(i=0;i<e;i++){
        printf("Enter source, destination and weight of edge %d: ",i+1);
        scanf("%d %d %d",&edges[i].src,&edges[i].dest,&edges[i].weight);
    }
    sort(edges,e);
    for(i=0;i<n;i++){
        parent[i]=i;
    }
    printf("Edges in the Minimum Spanning Tree:\n");
    for(i=0;i<e;i++){
        int x=find(edges[i].src);
        int y=find(edges[i].dest);
        if(x!=y){
            printf("%d -- %d == %d\n",edges[i].src,edges[i].dest,edges[i].weight);
            union1(x,y);
        }
    }
    return 0;
}