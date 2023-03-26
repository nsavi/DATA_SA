#include<stdio.h>
#define size 10
int q1[size];
int q2[size];
int q3[size];
int f1 = -1, r1 = -1;
int f2 = -1, r2 = -1;
int f3 = -1, r3 = -1;

void enqueue(int q[], int *f, int *r, int val)
{
    if(*r==size -1)
        printf("Queue is full");
    else
    {
        if(*f == -1)
            *f = 0;
        (*r)++;
        q[*r]=val;
    }
}

int dequeue(int q[], int *f, int *r)
{
    int x;
    if(*f==-1)
        printf("Queue is empty");
    else
    {
        x = q[*f];
        (*f)++;
        if(*f>*r)
            *f=*r=-1;
        return x;
    }
}

void subtract_queues() 
{
  if (r1 != r2) {
    printf("Queues have different sizes.\n");
    return;
  }
  while (f1!=-1 && f2!=-1)
  {
    int x = dequeue(q1, &f1, &r1);
    int y = dequeue(q2, &f2, &r2);
    int z = x - y;
    enqueue(q3, &f3, &r3, z);
  }
}

int display(int q[], int f, int r)
{
    if(r==-1)
        printf("Queue is empty");
    else
    {
        int i;
        printf("Queue elements are :");
        for(i=f;i<=r;i++)
            printf("\t%d",q[i]);
    }
}

int main() {
  enqueue(q1, &f1, &r1, 10);
  enqueue(q1, &f1, &r1, 20);
  enqueue(q1, &f1, &r1, 30);
  enqueue(q2, &f2, &r2, 5);
  enqueue(q2, &f2, &r2, 10);
  enqueue(q2, &f2, &r2, 15);
  
  subtract_queues();

  while (f3!=-1) 
  {
    printf("%d ", dequeue(q3, &f3, &r3));
  }
  printf("\n");
  return 0;
}
