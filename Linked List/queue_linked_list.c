// Queue Using Linked list
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* newNode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

// Initialize queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation
void enqueue(struct Queue* q, int value) {
    struct Node* temp = newNode(value);

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
    printf("%d enqueued\n", value);
}

// Dequeue operation
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }

    struct Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;

    // If queue becomes empty
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return val;
}

// Display queue
void display(struct Queue* q) {
    struct Node* temp = q->front;
    if (temp == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    display(q);

    enqueue(q, 40);
    display(q);

    return 0;
}