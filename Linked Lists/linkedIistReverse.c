#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL, *temp;

void cll(int n){
    struct node *newnode;
    for(int i=0; i<n; i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter %d element: ",(i+1));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL){
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void reverse(){
    if(head == NULL){
        printf("List is empty!");
        return;
    }
    struct node *current, *prev, *nextnode;
    prev = NULL, current = head, nextnode = head;

    while(nextnode != NULL){
        nextnode = nextnode->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }

    head = prev;
}

void dis(){
    temp = head;
    printf("\nLinked List:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
}

int main(){
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    cll(n);
    dis();

    reverse();
    printf("\nAfter Reversed:");
    dis();

    return 0;
}
