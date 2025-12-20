#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head=NULL, *temp;


void insertatbegin(int num){
    struct node *nnode;
    nnode = (struct node*)malloc(sizeof(struct node));
    if(nnode == NULL){
        printf("Memory not allocated!");
    }else{
        nnode->data = num;
        nnode->next = head;
        head = nnode;
    }
}

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

int insertbetween(int num,int pos){
    struct node *nnode, *tmp;
    int i;
    nnode = (struct node*)malloc(sizeof(struct node));
    if(nnode == NULL){
        printf("Memory not allocated!");
    }else{
        nnode->data = num;
        nnode->next = NULL;
        if(pos == 1){
            nnode->next = head;
            head = nnode;
        }else{
            tmp = head;
            int i=1;
            while(i < pos-1 && tmp != NULL){
                tmp = tmp->next;
                i++;
            }
            if(tmp == NULL){
                printf("Position is out of bounds!\n");
                return -1;
            }
            nnode->next = tmp->next;
            tmp->next = nnode;
        }
    }
}

int main(){
    int n,num,pos;
    printf("Enter the number of node:");
    scanf("%d",&n);

    CreateLinkedList(n);
    printf("Data enter in the list are:\n");
    display();
    
    printf("\nInput data to insert at the list : ");
    scanf("%d", &num);
    printf("Input the position to insert new node : ");
    scanf("%d", &pos);
    
    int result = insertbetween(num, pos);
    if(result == -1){
        printf("\nInsertion failed.\n");
    }else{
        printf("\nInsertion completed successfully.\n");
    }
    display();

    return 0;
}