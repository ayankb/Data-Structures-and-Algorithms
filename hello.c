#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char prefix[200];
    char *tokens[100];
    int count = 0;
    int i, op1, op2, result;

    printf("Enter prefix expression (comma separated):\n");
    fgets(prefix, sizeof(prefix), stdin);

    prefix[strcspn(prefix, "\n")] = '\0';

    char *token = strtok(prefix, ",");
    while (token != NULL) {
        tokens[count++] = token;
        token = strtok(NULL, ",");
    }

    for (i = count - 1; i >= 0; i--) {

        if (isdigit(tokens[i][0]) ||
           (tokens[i][0] == '-' && isdigit(tokens[i][1]))) {
            push(atoi(tokens[i]));
        }
        else {  
            op1 = pop();
            op2 = pop();

            switch (tokens[i][0]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
                default:
                    printf("Invalid operator\n");
                    return 1;
            }
            push(result);
        }
    }

    printf("Result = %d\n", pop());
    return 0;
}
