// Code for converting Decimal to binary using stacks .
# include <stdio.h>
# define max 50
int top = -1;
int stack[max];

void push(int num);
int pop();

void push(int x) {
    if (top == max - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = x;
}

int pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

void main()
{
    int num , rem , x;
    printf("Enter the number:");
    scanf("%d",&num);
    x = num;
    while(x > 0)
    {
        rem = x % 2;
        push(rem);
        x = x/2;
    }
    printf("%d in binary is :",num);
    while(top != -1)
    {
        printf("%d",pop());
    }
}