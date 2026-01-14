#include <stdio.h>
#include <string.h>
#include <ctype.h>

// stack implementation
char stack[100];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }
int isEmpty() { return top == -1; }

// precedence of operators
int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

// check if operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// check if operator is right-associative
int isRightAssociative(char c) {
    return (c == '^');
}

// function to convert infix to prefix using reverse-trick
void infixToPrefix(char s[]) {
    int n = strlen(s);

    // reverse string
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }

    // swap '(' and ')'
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    char result[200];
    int k = 0;

    // infix to postfix conversion
    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (isalnum(c)) {
            result[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                result[k++] = pop();
            }
            if (!isEmpty()) pop();
        }
        else if (isOperator(c)) {
            while (!isEmpty()&&
                  (precedence(peek()) > precedence(c) ||
                  (precedence(peek()) == precedence(c) && isRightAssociative(c)))) {
                result[k++] = pop();
            }
            push(c);
        }
    }

    while (!isEmpty()) {
        result[k++] = pop();
    }
    result[k] = '\0';

    // reverse result for prefix
    for (int i = 0; i < k / 2; i++) {
        char temp = result[i];
        result[i] = result[k - i - 1];
        result[k - i - 1] = temp;
    }

    printf("%s\n", result);
}

int main() {
    char s[] = "K+L-M*N+(O^P)*W/U/V*T+Q";
    infixToPrefix(s);
    return 0;
}