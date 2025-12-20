#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head=NULL, *temp;

void CreateLinkedList(int n){
    struct node *new_node; 
    int item, i;

    for(i=0; i<n; i++){
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter element %d: ",(i+1));
        scanf("%d",&item);   
        new_node->data = item;
        new_node->next = NULL;
        
        if(head == NULL){
            head = new_node;
            temp = new_node;
        } else {
            temp->next = new_node;
            temp = new_node;
        }
    }
}

void display(){
    if(head == NULL){
        printf("List is empty!");
    }else{
        temp = head;
        printf("Elements of Linked List:\n");
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

void DelFirstN(){
    if(head == NULL){
        printf("List is empty, nothing to delete.");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
}

int main(){
    int n;

    printf("Enter the number of node: ");
    scanf("%d",&n);
    CreateLinkedList(n);
    printf("Before deletion:\n");
    display();

    DelFirstN();
    printf("\nAfter deletion of first node:\n");
    display();

    return 0;
}