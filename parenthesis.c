#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Stack data structure implementation using a global array
char stack[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(char element) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = element;
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack[top--];
}

// Function to check if the brackets are balanced
int areBracketsBalanced(char* exp) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (top == -1) {
                return 0;
            } else if ((exp[i] == ')' && stack[top] == '(') ||
                       (exp[i] == ']' && stack[top] == '[') ||
                       (exp[i] == '}' && stack[top] == '{')) {
                pop();
            } else {
                return 0;
            }
        }
    }
    return (top == -1);
}

// Main function to test the program
int main() {
    char exp[MAX_SIZE];
    printf("Enter an expression: ");
    fgets(exp, MAX_SIZE, stdin);

    if (areBracketsBalanced(exp)) {
        printf("The brackets are balanced\n");
    } else {
        printf("The brackets are not balanced\n");
    }

    return 0;
}
