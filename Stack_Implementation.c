#include<stdio.h>
#define MAX 10
int stack[MAX];
int top = -1;
int data,i;

void push()
{
    if(top==MAX-1)
        printf("Stack Overflow\n");
    else
    {
        printf("Enter the value:");
        scanf("%d",&data);
        top=top+1;
        stack[top]=data;
        printf("Pushed %d onto the stack\n",data);
    }
}

int pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
        return -1; // return a sentinel value to indicate error
    }
    else
    {
        int popped_value = stack[top];
        printf("Popped %d from the stack\n",popped_value);
        top=top-1;
        return popped_value;
    }
}

void display()
{
    if(top==-1)
        printf("Stack is Empty\n");
    else
    {
        printf("Contents of the stack are:\n");
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.display\n");
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("Exiting...\n");
                return 0; // exit the program
            }
            default:
            {
                printf("Please Enter a Valid choice !\n");
                break; // add a break statement to avoid executing the default case multiple times
            }
        }
    }
    
}
