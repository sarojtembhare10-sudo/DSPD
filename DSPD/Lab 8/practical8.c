#include <stdio.h>
int parent[30];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}
int main() {
    int n, edges;
    int u, v, w;
    int cost = 0, count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    int graph[edges][3];

    printf("Enter each edge with weight (u v w):\n");
    for (int i = 0; i < edges; i++)
        scanf("%d %d %d", &graph[i][0], &graph[i][1], &graph[i][2]);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    for (int i = 0; i < edges - 1; i++)
        for (int j = 0; j < edges - i - 1; j++)
            if (graph[j][2] > graph[j + 1][2]) {
                int temp0 = graph[j][0];
                int temp1 = graph[j][1];
                int temp2 = graph[j][2];
                graph[j][0] = graph[j + 1][0];
                graph[j][1] = graph[j + 1][1];
                graph[j][2] = graph[j + 1][2];
                graph[j + 1][0] = temp0;
                graph[j + 1][1] = temp1;
                graph[j + 1][2] = temp2;
            }

    printf("\nEdges in the Minimum Spanning Tree:\n");

    for (int i = 0; i < edges; i++) {
        u = graph[i][0];
        v = graph[i][1];
        w = graph[i][2];

        int setU = find(u);
        int setV = find(v);

        if (setU != setV) {
            printf("%d - %d : %d\n", u, v, w);
            cost += w;
            unionSets(setU, setV);
            count++;
            if (count == n - 1)
                break;
        }
    }

    printf("\nTotal cost of Minimum Spanning Tree = %d\n", cost);
    return 0;
}
