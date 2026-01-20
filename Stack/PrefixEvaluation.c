#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int stack[100];
int top = -1;

void push(int ch){
    stack[++top] = ch;
}

int pop(){
    return stack[top--];
}

int main(){
    char prefix[100];
    char *tokens[100];
    char ch;
    int count = 0;
    int i, op1, op2, result;

    printf("Enter prefix expression(comma separated):\n");
    fgets(prefix, sizeof(prefix), stdin);

    prefix[strcspn(prefix, "\n")] = '\0';

    char *token = strtok(prefix, ",");
    while(token != NULL){
        tokens[count++] = token;
        token = strtok(NULL, ",");
    }

    for(i = count-1; i >= 0; i--){
        ch = tokens[i][0];
        if(isdigit(ch)) {
            push(atoi(tokens[i]));
        } else{
            op1 = pop();
            op2 = pop();
            switch (ch)
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
    }

    printf("Result: %d\n", stack[top]);
    return 0;
}