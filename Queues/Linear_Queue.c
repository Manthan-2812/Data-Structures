// Queue - Data Structure 
#include<stdio.h>
#include<stdlib.h>
# define MAX 5

// Linear Queue ->
int a[MAX], front = -1 , rear = -1;

void display()
{
    if(front == -1 || front>rear)
    {
        printf("Queue is Empty.");
        printf("\n-------------------------------------\n");
    }
    else
    {
        int temp = front;
        printf("The Queue is:\n");
        for(temp = front;temp<=rear;temp++)
        {
            printf("%d\t",a[temp]);
        }
        printf("\n-------------------------------------\n");
    }
}

void enqueue(int data);
void enqueue(int data)
{
    if(rear == MAX-1)
    {
        printf("Queue is full");
        printf("\n-------------------------------------\n");
    }
    else if(front == -1)
    {
        front++;
        rear++;
        a[rear] = data;
        display();
    }
    else
    {
        rear++;
        a[rear] = data;
        display();
    }
}

void dequeue();
void dequeue()
{
    if(front == -1 || front>rear)
    {
        printf("Queue is Empty.");
        printf("\n-------------------------------------\n");
    }
    else if(front==rear)
    {
        int temp = a[front];
        printf("Element removed:%d\n",temp);
        printf("Queue is Empty now\n");
        front = -1;
        rear = -1;
        display();
    }
    else
    {
        int temp = a[front];
        front++;
        printf("Element removed:%d\n",temp);
        display();
    }
}

void main()
{
    int n,element;
    do
    {
    printf("Enter\n 1.Enqueue.\n 2.Dequeue.\n 3.Exit\n");
    scanf("%d",&n);
    printf("\n-------------------------------------\n");
    switch(n)
    {
        case 1: printf("Enter element to enqueue:\t");
                scanf("%d",&element);
                enqueue(element);
                break;
        case 2: dequeue();
                break;
        case 3: printf("Program Terminated.");
                exit(0);
        default: printf("Inavlid Choice.\nEnter again.");
                 printf("\n-------------------------------------\n");
    }
    }while(n != 3);
}