#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
} *head=NULL, *temp;

void cll(int n){
    struct node *nnode;
    for(int i=0; i<n; i++){
        nnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter %d: ", (i+1));
        scanf("%d", &nnode->data);
        nnode->next = NULL;
        if(head == NULL){
            head = nnode;
            temp = nnode;
        } else {
            temp->next = nnode;
            temp = temp->next;
        }
    }
}

void dis(){
    if(head == NULL){
        printf("LinkedList is empty.");
    } else {
        temp = head;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void re(){
    struct node *current_node, *pre_node, *next_node;
    current_node = head;
    pre_node = NULL;
    next_node = head;
    while(next_node != NULL){
        next_node = next_node->next;
        current_node->next = pre_node;
        pre_node = current_node;
        current_node = next_node;
    }
    head = pre_node;
}

int main(){
    int n;
    printf("Enter the size of List: ");
    scanf("%d", &n);
    cll(n);
    dis();
    re();
    dis();
    return 0;

}