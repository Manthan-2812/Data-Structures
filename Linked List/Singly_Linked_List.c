#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *list=NULL,*last=NULL,*temp;

struct Node *createNode(int info)
{
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = info;
    n->next = NULL;
    return n;
}

void insertatEnd(int info)
{
    struct Node *n = createNode(info);
    if(list==NULL)
        list=last=n;
    else
    {
        last->next=n;
        last=n;
    }
}

void display()
{
    temp=list;
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void main()
{
    insertatEnd(10);
    insertatEnd(20);
    display();
}
