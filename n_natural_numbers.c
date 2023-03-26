#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int stack[MAX_SIZE];
int front = -1, rear = -1;
int top = -1;
int expected = 1;

void enqueue(int element) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue overflow\n");
        exit(1);
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = element;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        exit(1);
    }
    int element = queue[front];
    front++;
    return element;
}

void push(int element) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    top++;
    stack[top] = element;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    int element = stack[top];
    top--;
    return element;
}

bool is_queue_arrangeable() {
    while (front <= rear) {
        int element = dequeue();
        if (element == expected) {
            expected++;
        } else {
            push(element);
        }
    }
    while (top != -1) {
        int element = pop();
        if (element == expected) {
            expected++;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the elements of the queue: ");
    for (int i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);
        enqueue(element);
    }
    bool result = is_queue_arrangeable();
    if (result) {
        printf("The given queue can be arranged in increasing order using a stack\n");
    } else {
        printf("The given queue cannot be arranged in increasing order using a stack\n");
    }
    return 0;
}
