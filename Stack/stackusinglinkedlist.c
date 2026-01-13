#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
} *top = NULL, *temp;

void push(int val){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL){
        printf("Overflow. Stack is full.");
        return;
    }

    newnode->data = val;
    newnode->next = top;
    top = newnode;
    printf("%d push on the stack.\n", val);
}

void pop(){
    temp = top;
    if(top == NULL){
        printf("Underflow. Stack is empty.");
        return;
    }
    top = top->next;
    printf("%d pop from the stack.\n", temp->data);
    free(temp);
}

void peek(){
    if(top == NULL){
        printf("Underflow. Stack is empty.");
        return;
    }
    printf("%d top element of stack.\n", top->data);
}

void display(){
    if(top == NULL){
        printf("Underflow. Stack is empty.");
        return;
    }
    printf("Elements of stack:\n");
    temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    int c, item;
    printf("1 for push.\n2 for pop.\n3. Show top element.\n4 for Display.\n5 for exit\n");

    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter item to push in stack: ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            printf("Element of stack:\n");
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid input.");
            break;
        }
    }

    return 0;
}