#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* CreateNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insertNode(struct Node* root, int val){
    if(root == NULL){
        return CreateNode(val);
    }
    if(val < root->data){
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }

    return root;
}

struct Node* search(struct Node* root, int key){
    if(root == NULL || root->data == key){
        return root;
    } else if(key < root->data){
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main(){
    struct Node* root = NULL;
    int n, value;
    printf("Enter the size of list: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter element %d: ", (i+1));
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    // printf("\nInorder Traversal:\n");
    // inorder(root);

    int key;
    printf("Enter key: ");
    scanf("%d", &key);
    if(search(root, key)){
        printf("%d found.");
    } else {
        printf("%d not found.");
    }

    return 0;
}