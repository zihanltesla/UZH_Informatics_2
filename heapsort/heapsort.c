#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct node *root) {
    if (root == NULL) return;

    struct node *largest = root;
    if (root->left != NULL && root->left->data > largest->data) {
        largest = root->left;
    }
    if (root->right != NULL && root->right->data > largest->data) {
        largest = root->right;
    }
    if (largest != root) {
        swap(&root->data, &largest->data);
        heapify(largest);
    }
}

void buildHeap(struct node *root) {
    if (root == NULL) return;
    heapify(root->left);
    heapify(root->right);
    heapify(root);
}

void printHeap(struct node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    if(root->left != NULL){
        printf("%d ", root->left->data);
    }
    if(root->right != NULL){
        printf("%d ", root->right->data);
    }
    if (root->left != NULL) {
        printHeap(root->left);
    }
}

int main() {
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = 1;
    root->left = (struct node *)malloc(sizeof(struct node));
    root->left->data = 2;
    root->right = (struct node *)malloc(sizeof(struct node));
    root->right->data = 3;
    root->left->left = (struct node *)malloc(sizeof(struct node));
    root->left->left->data = 4;
    root->left->right = (struct node *)malloc(sizeof(struct node));
    root->left->right->data = 5;
    root->right->left = (struct node *)malloc(sizeof(struct node));
    root->right->left->data = 6;
    root->right->right = (struct node *)malloc(sizeof(struct node));
    root->right->right->data = 7;

    // Set children of leaf nodes to NULL
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    buildHeap(root);
    printHeap(root);
    return 0;
}
