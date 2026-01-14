#include<stdio.h>
#include<ctype.h>
#include<string.h>

int stack[100];
int top = -1;

void push(char ch){
    stack[++top] = ch;
}

int pop(){
    return stack[top--];
}

int main(){
    char exp[100];
    char ch;
    int i, op1, op2, result;

    printf("Enter prefix expr:\n");
    scanf("%s", exp);

    int len = strlen(exp);
    for(i = len-1; i >= 0; i--){
        ch = exp[i];
        if(isdigit(ch)) {
            push(ch - '0');
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
                result = op1 ^ op2;
            default:
                break;
            }
            push(result);
        }
    }

    printf("Result: %d", stack[top]);
    return 0;
}