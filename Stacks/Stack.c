#include <stdio.h>
#define max 50

int stack[max];
int top = -1;

void push(int data);
void display();
void pop();

void push(int data) {
    if(top == max-1) {
        printf("Stack overflow");
    } else {
        top++;
        stack[top] = data;
        printf("\n %d inserted into stack.\n", data);
    }
    display();
    printf("\n------------------------\n");
}

void pop() {
    if(top == -1) {
        printf("Undervalued");
    } else {
        printf("%d extracted from stack", stack[top]);
        top--;
    }
}

void display() {
    int i;
    if(top == -1) {
        printf("Undervalued");
    } else {
        printf("The stack is: \n");
        for(i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main(void) {
    int data[max];
    printf("Enter the element you want to add in stack: \n");
    for(int i = 0; i < 5; i++) { // Adjusted loop for testing
        scanf("%d", &data[i]);
        push(data[i]);
    }
    pop();
    return 0;
}
