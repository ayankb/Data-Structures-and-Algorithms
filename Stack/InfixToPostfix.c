#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char ch){
    top++;
    stack[top] = ch;
}

char pop(){
    return stack[top--];
}

int prec(char ch){
    if(ch == '+' || ch == '-'){
        return 1;
    }
    if(ch == '*' || ch == '/'){
        return 2;
    }
    if(ch == '^'){
        return 3;
    }
    return 0;
}

int RightAssociative(char ch){
    return ch == '^';
}

int main(){
    char infix[100], postfix[100];
    int i=0, j=0;
    char ch;
    printf("Enter Infix:\n");
    scanf("%s", &infix);

    while(infix[i] != '\0'){
        ch = infix[i];
        if(isalnum(ch)){
            postfix[j++] = ch;
        } else if(ch == '('){
            push(ch);
        } else if(ch == ')'){
            while(top != -1 && stack[top] != '('){
                postfix[j++] = pop();
            }
            pop();
        } else {
            while(top != -1 && prec(stack[top]) >= prec(ch) && !RightAssociative(ch)){
                postfix[j++] = pop();
            }
            push(ch);
        }
        i++;
    }

    while(top != -1){
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    printf("Postfix:\n");
    printf("%s", postfix);
    return 0;
}
