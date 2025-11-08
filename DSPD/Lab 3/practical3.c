#include <stdio.h>
#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

void insert(char val) {
    if (rear == MAX - 1)
        printf("Queue Overflow!\n");
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = val;
        printf("'%c' inserted into queue.\n", val);
    }
}

void delete() {
    if (front == -1 || front > rear)
        printf("Queue Underflow!\n");
    else {
        printf("'%c' deleted from queue.\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear)
        printf("Queue is Empty.\n");
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%c ", queue[i]);
        printf("\n");
    }
}

int main() {
    int ch;
    char val;
    do {
        printf("\n1.Insert into queue\n2.Delete from queue\n3.Display queue elements\n4.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &val);
                insert(val);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (ch != 4);
    return 0;
}
