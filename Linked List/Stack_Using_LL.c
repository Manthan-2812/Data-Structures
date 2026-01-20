 #include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Top pointer (head of stack)
struct Node* top = NULL;

// Create a new node
struct Node* createNode(int value);
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Push operation
void push(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = top;  // link new node to previous top
    top = newNode;        // update top
    printf("%d pushed to stack\n", value);
}

// Pop operation
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Cannot pop.\n");
        return;
    }
    struct Node* temp = top;
    printf("%d popped from stack\n", temp->data);
    top = top->next;  // move top to next node
    free(temp);
}

// Peek operation (top element)
void peek() {
    if (top == NULL) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

// Display all elements
void display() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
void main() {
    int choice, value;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
   // return 0;
}