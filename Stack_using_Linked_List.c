#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
}*top = NULL;

void push(int x)
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->data=x;
    if(top == NULL)
    {
    n->next=NULL;
        top=n;
    }
    else
    {
        n->next=top;
        top= n;
    }
    //printf("\nElement inserted");
}

int pop()
{
    struct node *temp;
    if(top == NULL)
        return -1;
    else 
    {
        temp = top;
        top = top->next;
        //printf("\nElement popped:%d",temp->data);
        free(temp);
    }
}

void display()
{
    struct node *i;
    for(i=top;i!=NULL;i=i->next)
        printf("%d ",i->data);
}

int main()
{
    int no,i,x;
    scanf("%d",&no);
    for(i=0;i<no;i++)
    {
        scanf("%d",&x);
        push(x);
    }
    display();
    return 0;
}
