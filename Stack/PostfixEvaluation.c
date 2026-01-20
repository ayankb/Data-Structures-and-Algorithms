#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int stack[100];
int top = -1;

void push(int ch){
    stack[++top] = ch;
}

int pop(){
    return stack[top--];
}

int main(){
    char postfix[100];
    char *token;
    int i=0, op1, op2, result;
    printf("Enter postfix expression (comma separated):\n");
    fgets(postfix, sizeof(postfix), stdin);

    postfix[strcspn(postfix, "\n")] = '\0';

    token = strtok(postfix, ",");

    while(token != NULL){
        
        if(isdigit(token[0])) {
            push(atoi(token));
        } else{
            op2 = pop();
            op1 = pop();
            switch (token[0])
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            case '^':
                result = pow(op1, op2);
            default:
                break;
            }
            push(result);
        }
        token = strtok(NULL, ",");
    }

    printf("Result: %d", stack[top]);
    return 0;
}