#include <stdio.h>
#define MAX 10
int AM[MAX][MAX];
int n;
void DFS() {
    int stack[MAX], top = -1,visited[MAX], i, k;
    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("enter start node: ", n - 1);
    scanf("%d", &k);

    stack[++top] = k;
    visited[k] = 1;

    printf("DFS order: ");
    while (top >= 0) {
        k = stack[top--];
        printf("%d ", k);

        for (i = 0; i < n; i++) {
            if (AM[k][i] && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}
void BFS() {
    int q[MAX], front = 0, rear = 0;
    int visited[MAX], i, k;
    for (i = 0; i < n; i++)
        visited[i] = 0;
    printf("\nenter start node: ", n - 1);
    scanf("%d", &k);
    q[rear++] = k;
    visited[k] = 1;
    printf("BFS order: ");
    while (front < rear) {
        k = q[front++];
        printf("%d ", k);
        for (i = 0; i < n; i++) {
            if (AM[k][i] && !visited[i]) {
                q[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}
int main() {
    int i, j, choice;
    printf("enter number of nodes : ", MAX);
    scanf("%d", &n);
    printf("enter adjacency matrix :\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &AM[i][j]);
    do {
        printf("\nMENU\n");
        printf("1. display adjacency matrix\n");
        printf("2. DFS order:\n");
        printf("3. BFS order\n");
        printf("4. exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++)
                        printf("%d ", AM[i][j]);
                    printf("\n");
                }
                break;
            case 2:
                DFS();
                break;
            case 3:
                BFS();
                break;
            case 4:
                printf("exiting\n");
                break;
            default:
                printf("enter a valid choice\n");
        }
    } while (choice != 4);
    return 0;
}
