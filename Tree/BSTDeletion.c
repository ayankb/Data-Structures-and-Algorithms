#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct Node* findMin(struct Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

struct Node* deleteNode(struct Node* root, int key){
    if(root == NULL){
        return root;
    } 
    if(key < root->data){
        root->left = deleteNode(root->left, key);
    } else if(key > root->data){
        root->right = deleteNode(root->right, key);
    } else {
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        } else if(root->left == NULL){
            struct Node* rightChild = root->right;
            free(root);
            return rightChild;
        } else if(root->right == NULL){
            struct Node* leftChild = root->left;
            free(root);
            return leftChild;
        } else {
            struct Node* min = findMin(root->right);
            root->data = min->data;
            root->right = deleteNode(root->right, min->data);
        }
    }

    return root;
}

int main() {
    struct Node* root = NULL;
    int n, value;
    printf("Enter the size of list: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter element %d: ", (i+1));
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("\nInorder Traversal:\n");
    inorder(root);

    root = deleteNode(root, 50);
    printf("\nAfter Delete Inorder Traversal:\n");
    inorder(root);

    return 0;
}

