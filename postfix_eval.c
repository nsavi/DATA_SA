#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void push(long int character);
long int postfix_evaluation();
int pop();
int isEmpty();
int top;
long int stack[50];
char postfix_expression[50];

int main()
{
    long int evaluated_value;
    top = -1;
    printf("\nEnter an Expression in Postfix format:\t");
    scanf("%[^\n]s", postfix_expression);
    printf("\nExpression in Postfix Format: \t%s\n", postfix_expression);
    evaluated_value = postfix_evaluation();
    printf("\nEvaluation of Postfix Expression: \t%ld\n", evaluated_value);
    return 0;
}

long int postfix_evaluation()
{
    long int x, y, temp, value;
    int count;

    for(count = 0; count < strlen(postfix_expression); count++)
    {
        if(postfix_expression[count] <= '9' && postfix_expression[count] >= '0')
        {
            push(postfix_expression[count] - '0');
        }
        else
        {
            x = pop();
            y = pop();
            switch(postfix_expression[count])
            {
                case '+': temp = y + x;
                          break;
                case '-': temp = y - x;
                          break;
                case '*': temp = y * x;
                          break;
                case '/': temp = y / x;
                          break;
                case '%': temp = y % x;
                          break;
                case '^': temp = pow(y, x);
                          break;
                default: printf("Invalid");
                         break;
            }
            push(temp);
        }
    }
    value = pop();
    return value;
}

void push(long int character)
{
    if(top > 50)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    top = top + 1;
    stack[top] = character;
}

int pop()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
        exit(1);
    }
    return(stack[top--]);
}

int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
