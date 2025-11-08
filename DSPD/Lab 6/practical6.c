#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}
struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
struct node* deleteLeaf(struct node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteLeaf(root->left, key);
    else if (key > root->data)
        root->right = deleteLeaf(root->right, key);
    else {
        // Check if it's a leaf node
        if (root->left == NULL && root->right == NULL) {
            printf("\nLeaf node %d deleted.", key);
            free(root);
            return NULL;
        } else {
            printf("\nNot a leaf node. Cannot delete.");
        }
    }
    return root;
}
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main() {
    struct node* root = NULL;
    int choice, value;
    struct node* result;

    do {
        printf("\n\n--- Binary Search Tree Menu ---");
        printf("\n1. Search an element in BST");
        printf("\n2. Insert an element in BST");
        printf("\n3. Delete leaf element in BST");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &value);
                result = search(root, value);
                if (result == NULL)
                    printf("NULL (Not Found)");
                else
                    printf("Found");
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted Successfully!");
                printf("\nCurrent Inorder Traversal: ");
                inorder(root);
                break;

            case 3:
                printf("Enter leaf node to delete: ");
                scanf("%d", &value);
                root = deleteLeaf(root, value);
                printf("\nCurrent Inorder Traversal: ");
                inorder(root);
                break;

            case 4:
                printf("Exiting program...");
                break;

            default:
                printf("Invalid choice!");
        }
    } while (choice != 4);

    return 0;
}
