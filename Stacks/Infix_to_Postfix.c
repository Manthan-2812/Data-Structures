# include <stdio.h>
# define max 50
#include <ctype.h>

int priority(char x);
void push(char x);
char pop();

#define max 50
char stack[max];
int top = -1;

void push(char x) {
    if (top == max - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return -1;
}

int main() {
    char exp[100], *e, x;
    printf("Enter infix expression: ");
    scanf("%s", exp);
    printf("\nPostfix expression: ");

    e = exp;
    while (*e != '\0') {
        if (isalnum(*e)) { // Check if the pointer pointing to entered expression array is character or not .
            printf("%c", *e);
        } else if (*e == '(') {
            push(*e);
        } else if (*e == ')') {  /* when the pointer while travesing array points the right paranthesis it checks first whether the
                                    pop character from stack is '('  or not if not then print all the operators in stack unitil it founds (left paranthesis) */
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        } else {
            while ( priority(stack[top]) >= priority(*e)) { /* when pointer of array points at operator it compares with the operator in stack and accordingly it
                                                            pushes the element and pops out element . */
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }
    // this returns after whatever operators are remaining in stack
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");
    return 0;
}