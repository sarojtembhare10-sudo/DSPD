#include <stdio.h>

#define INF 9999
#define MAX 20

int findParent(int v, int parent[]) {
    if (parent[v] == v)
        return v;
    return findParent(parent[v], parent);
}

void unionSet(int u, int v, int parent[]) {
    int a = findParent(u, parent);
    int b = findParent(v, parent);
    parent[a] = b;
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[MAX][MAX];

    printf("Enter the cost adjacency matrix (enter 0 if no edge):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    int parent[MAX];
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int edgeCount = 0, total = 0;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (edgeCount < n - 1) {
        int min = INF, a = -1, b = -1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (findParent(i, parent) != findParent(j, parent) &&
                    cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        if (a != -1 && b != -1) {
            printf("%d -- %d == %d\n", a, b, min);
            total += min;
            unionSet(a, b, parent);
            edgeCount++;
            cost[a][b] = cost[b][a] = INF;
        }
    }

    printf("\nTotal weight of MST = %d\n", total);
    return 0;
}
