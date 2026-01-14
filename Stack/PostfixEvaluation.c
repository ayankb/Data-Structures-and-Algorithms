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
    int i=0, op1, op2, result;
    printf("Enter postfix expr:\n");
    scanf("%s", exp);
    int len = strlen(exp);
    while(exp[i] != '\0'){
        ch = exp[i];
        if(isalnum(ch)) {
            push(ch - '0');
        } else{
            op2 = pop();
            op1 = pop();
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
        i++;
    }

    printf("Result: %d", stack[top]);
    return 0;
}