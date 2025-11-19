#include <stdio.h>

#define MAX 10
int AM[MAX][MAX], n;

void DFS() {
    int stack[MAX], top = -1, visited[MAX];
    int i, k, start;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter start node for DFS: ");
    scanf("%d", &start);
    stack[++top] = start;
    visited[start] = 1;

    printf("DFS Traversal: ");
    while (top >= 0) {
        k = stack[top--];
        printf("%d ", k);
        for (i = n - 1; i >= 0; i--) {
            if (AM[k][i] == 1 && visited[i] == 0) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void BFS() {
    int q[MAX], front = -1, rear = -1, visited[MAX];
    int i, k, start;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter start node for BFS: ");
    scanf("%d", &start);
    q[++rear] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (front != rear) {
        k = q[++front];
        printf("%d ", k);
        for (i = 0; i < n; i++) {
            if (AM[k][i] == 1 && visited[i] == 0) {
                q[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &AM[i][j]);
        }
    }
    DFS();
    BFS();
    return 0;
}
