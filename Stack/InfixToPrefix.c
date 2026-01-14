#include<stdio.h>
#include<string.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char ch){
    stack[++top] = ch;
}

char pop(){
    return stack[top--];
}

int prec(char ch){
    if(ch == '+' || ch == '-')
        return 1;
    if(ch == '*' || ch == '/')
        return 2;
    if(ch == '^')
        return 3;

    return 0;
}

int rightAssociative(char ch){
    return ch == '^';
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int main(){
    char infix[100], prefix[100], temp[100];
    int i, j=0, k=0;
    char ch;
    printf("Enter Infix:\n");
    scanf("%s", infix);

    int len = strlen(infix);
    for(i = len-1; i >= 0; i--){
        if(infix[i] == '(')
            temp[k++] = ')';
        else if(infix[i] == ')')
            temp[k++] = '(';
        else
            temp[k++] = infix[i];
    }
    temp[k] = '\0';

    i=0;
    while(temp[i] != '\0'){
        ch = temp[i];
        if(isalnum(ch)){
            prefix[j++] = ch;
        } else if(ch == '('){
            push(ch);
        } else if(ch == ')'){
            while(stack[top] != '('){
                prefix[j++] = pop();
            }
            pop();
        } else {
                while (top != -1 &&
                  (prec(stack[top]) > prec(ch) ||
                  (prec(stack[top]) == prec(ch) && rightAssociative(ch)))) {
                    prefix[k++] = pop();
            }
                push(ch);
        }
        i++;
    }

    while(top != -1){
        prefix[j++] = pop();
    }
    prefix[j] = '\0';
    strrev(prefix);

    printf("Prefix:\n");
    printf("%s", prefix);
    return 0;

}