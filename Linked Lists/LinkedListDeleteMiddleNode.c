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

void DelMiddleNode(int pos){
    struct node *current = head, *prv = NULL;
    int i=0;
    if(head == NULL){
        printf("List is empty!");
        return;
    }

    if(pos == 0){
        head = head->next;
        free(current);
        return;
    }

    while(i < pos-1 && current != NULL){
        prv = current;
        current = current->next;
        i++;
    }
    if(prv != NULL && current != NULL){
        prv->next = current->next;
        free(current);
    } else {
        printf("Position is out of bounds!\n");
    }

}

int main(){
    int n, pos;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    CreateLinkedList(n);
    display();

    printf("\nEnter position of node to delete: ");
    scanf("%d",&pos);

    DelMiddleNode(pos);
    display();
    
    return 0;
}