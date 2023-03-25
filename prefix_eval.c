#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

char prefix[MAX_SIZE];
int stack[MAX_SIZE];
int top = -1;

void push(int num) {
    if (top >= MAX_SIZE - 1) {
        printf("\nStack overflow.");
        exit(1);
    }
    stack[++top] = num;
}

int pop() {
    if (top < 0) {
        printf("\nStack underflow.");
        exit(1);
    }
    return stack[top--];
}

int prefix_evaluation() {
    int i, len, op1, op2, result;
    len = strlen(prefix);
    for (i = len - 1; i >= 0; i--) {
        if (isdigit(prefix[i])) {
            push(prefix[i] - '0');
        }
        else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/') {
            op1 = pop();
            op2 = pop();
            switch (prefix[i]) {
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
            }
            push(result);
        }
        else {
            printf("\nInvalid character in prefix expression.");
            exit(1);
        }
    }
    return pop();
}

int main() {
    printf("Enter prefix expression: ");
    scanf("%s", prefix);
    int result = prefix_evaluation();
    printf("Result: %d", result);
    return 0;
}
