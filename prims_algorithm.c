#include <stdio.h>
#define INF 9999
int main() {
    int n;
    int cost[10][10];
    int visited[10] = {0};
    int edges = 0;
    int min, u, v;
    int totalCost = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            // 0 means there is no edge
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }
    // Start from vertex 0
    visited[0] = 1;
    printf("\nEdges in Minimum Spanning Tree:\n");
    // MST contains n-1 edges
    while (edges < n - 1) {
        min = INF;
        u = -1;
        v = -1;
        // Find minimum edge between
        // visited and unvisited vertices
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        // Add selected edge
        visited[v] = 1;
        printf("%d - %d : %d\n", u, v, min);
        totalCost += min;
        edges++;
    }
    printf("\nMinimum Cost = %d\n", totalCost);
    return 0;
}