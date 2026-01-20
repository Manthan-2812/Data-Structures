#include<stdio.h>
#define SIZE 5
int a[SIZE], rear = -1, front = -1 ;

void enQueue(int data);
void enQueue(int data)
{
    if((rear+1)%SIZE == front)
    {
        printf("The Queue is FULL dequeue first.");
        printf("\n-------------------------------------\n");
        return;
    }
    else if(front == -1 && rear == -1)
    {
        front++;
        rear++;
        a[rear] = data; 
    }
    else 
    {
        rear = (rear + 1) % SIZE;
        a[rear] = data;
    }
}

void deQueue();
void deQueue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty. Enqueue first.");
        printf("\n-------------------------------------\n");
    }
    else if(front == rear) // This condition will arise only when there is  only one element left.
    {
        int temp = a[front];
        printf("Dequeued: %d", temp);
        printf("\nThe Queue is empty now ");
        printf("\n-------------------------------------\n");
        front = rear = -1;
    }
    else
    {
        int temp = a[front];
        printf("Dequeued: %d", temp);
        printf("\n-------------------------------------\n");
        front = (front + 1)%SIZE;
    }
}

void display();
void display()
{
    //int temp = front;
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty!\n");
        return;
    }
    // Handle two cases:
    if(front <= rear)  // Case 1: No wrap-around
    {
        for(int i = front; i <= rear; i++)
        {
            printf("%d\t", a[i]);  // ✓ No & symbol
        }
    }
    else  // Case 2: Wrap-around (front > rear)
    {
        // Print from front to end of array
        for(int i = front; i < SIZE; i++)
        {
            printf("%d\t", a[i]);
        }
        // Then print from start to rear
        for(int i = 0; i <= rear; i++)
        {
            printf("%d\t", a[i]);
        }
    }
    
    printf("\n");
    printf("Front = %d, Rear = %d\n", front, rear);
    printf("-------------------------------------\n");
}