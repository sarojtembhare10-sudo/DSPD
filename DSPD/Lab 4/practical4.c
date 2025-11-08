#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp = NULL, *newnode;
    int val, count = 0;

    printf("Enter numbers (0 to stop):\n");
    while (1) {
        scanf("%d", &val);
        if (val == 0)
            break;
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->next = NULL;

        if (head == NULL)
            head = temp = newnode;
        else {
            temp->next = newnode;
            temp = newnode;
        }
        count++;
    }

    printf("\nLinked List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d => ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    printf("\nTotal number of nodes = %d\n", count);
    return 0;
}
