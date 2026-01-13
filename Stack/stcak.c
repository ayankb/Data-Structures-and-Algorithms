#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct stack{
    int arr[MAX];
    int top;
};

void initstaxk(struct stack *s){
    s->top = -1;
}

void push(struct stack *s){
    int item;
    printf("Enter item to push in stack: "); 
    scanf("%d", &item);
    if(s->top == MAX-1){
        printf("Overflow. Stack is full.");
    } else {
        s->top++;
        s->arr[s->top] = item;
        printf("%d push on the stack.\n", item);
    }
}

void pop(struct stack *s){
    if(s->top == -1){
        printf("Underflow. Stack is empty.");
    } else {
        int item = s->arr[s->top];
        s->top--;
        printf("%d pop from the stack.\n", item);
    }
}

int peek(struct stack *s){
    printf("%d top element of stack.\n", s->arr[s->top]);
}

void dis(struct stack *s){
    if(s->top == -1){
        printf("Underflow. Stack is empty.");
        return;
    }
    for(int i=s->top; i>=0; i--){
        printf("%d ", s->arr[i]);
    }
}

int main(){
    struct stack s;
    initstaxk(&s);
    int c;
    printf("1 for push.\n2 for pop.\n3. Show top element.\n4 for Display.\n5 for exit\n");

    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            push(&s);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            peek(&s);
            break;
        case 4:
            printf("Element of stack:\n");
            dis(&s);
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
