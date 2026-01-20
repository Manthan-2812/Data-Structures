#include<stdio.h>
#include<stdlib.h>
// Create Node=>
int count = 0;
struct Node
{
    int data;
    struct Node * next;
    struct Node * prev; // for storing previous node
};
struct Node * node, *list = NULL, *last = NULL , *temp,*p;

struct Node * createNode(int info);
struct Node * createNode(int info)
{
     struct Node * node = (struct Node*) malloc(sizeof(struct Node));
     node -> data = info;
     node -> next = NULL;
     node -> prev = NULL;
     return node;
}

// Inserting node at front =>
void insertatFront(int info);
void insertatFront(int info)
{
    node = createNode(info);
    if(list == NULL)
    {
        list = node;
        last = node;
        count++;
    }
    else
    {
        node->next=list; // address of old node is stored at new pointer
        list->prev=node; // old node stores address of new node at front which is previous.
        list = node;
        count++;
    }
}

// Insert at End =>
void insertatEnd(int info);
void insertatEnd(int info)
{
    node = createNode(info);
    if(list == NULL)
    {
        list = node;
        last = node;
        count++;
    }
    else
    {
        node->prev = last;
        last->next =node;
        last = node;
        count++;
    }
}

// Insert at Index =>
void insertatIndex(int info,int n);
void insertatIndex(int info,int n)
{
    node = createNode(info);
    if(n<1 || n>count+1)
    {
        printf("Cannot Insert.");
        printf("\n---------------------------------------------\n");
    }
    if(n == 1)
    {
        insertatFront(info);
    }
    else if(n == count+1)
    {
        insertatEnd(info);
    }
    else
    {
        temp = list;
        for(int i = 1;i<n-1;i++)
        {
            temp = temp -> next;
        }
        p = temp -> next;
        node -> next = temp -> next;
        temp ->next = node;
        node -> prev = temp ;
        p->prev = node;
        count++;
        //free(temp);

    }

}

// Delete at front =>
void deleteatFront();
void deleteatFront()
{
    if(list == NULL)
    {
        printf("The list is empty.");
        printf("\n---------------------------------------------\n");
    }
    temp = list;
    if(list->next == NULL)
    {
        list = NULL;
        last = NULL;
       // count--;
    }
    else
    {
        list = list->next;
        list->prev = NULL;
    }
    printf("The deleted element is:\t %d",temp->data);
    printf("\n---------------------------------------------\n");
    free(temp);
    count--;
}

// Delete at End =>
void deleteatEnd();
void deleteatEnd()
{
    if(list == NULL)
    {
        printf("List is empty.");
        printf("\n---------------------------------------------\n");
    }
    if(list ->next == NULL)
    {
        deleteatFront();
    }
    else
    {
        temp = last;
        last = last -> prev;
        last -> next = NULL;
        printf("The deleted element is:\t%d",temp->data);
        printf("\n---------------------------------------------\n");
        free(temp);
        count--;
    }
}

// Delete at Index =>
void deleteatIndex(int i);
void deleteatIndex(int i)
{
    if(i<1 || i>count+1)
    {
        printf("Invalid Index.");
        ("\n---------------------------------------------\n");
    }
    if(i == count+1)
    {
        deleteatEnd();
    }
    if(i==1)
    {
        deleteatFront();
    }
    else
    {
        p = list;
        for(int j = 1;j<i;j++)
        {
            p = p->next;
        }
        temp = p;
        (p->next)->prev = p->prev; // jo node delete karna hai uska next node ka prev node delete node ka prev hoga assign.
        (p->prev)->next = p->next;
        printf("The deleted Element was\t%d",temp->data);
        printf("\n---------------------------------------------\n");
        free(temp);
        count--;
    }
}

// Forward Display =>
void display();
void display()
{
    if(list == NULL)
    {
        printf("The List is Empty.\n");
    }
    else
    {
        temp = list;
        printf("The Linked List is as follows:\n");
        while(temp != NULL)
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
        printf("\n Total number of Nodes : %d",count);
        printf("\n----------------------------\n");
    }
}

// Backward Display =>
void displayBack();
void displayBack()
{
   if(list == NULL)
    {
        printf("The List is Empty.\n");
    }
    else
    {
       temp = last;
        printf("The Linked List is as follows:\n");
        while(temp != NULL)
        {
            printf("%d\t",temp->data);
            temp = temp->prev;
        }
        printf("\n Total number of Nodes : %d",count);
        printf("\n----------------------------\n");
    }
}

void main()
{
    int data,n,j,g,m;
    while(n != 5)
    {
    printf("Enter\n 1. Insert.\n 2. Delete.\n 3. Forward Display.\n 4.Backward Display.\n 5. exit.\n");
    printf("\n------------------------------------------\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1: printf("\n Enter data :\t");
                scanf("%d",&data);
                printf("\n----------------------------\n");
                printf("Enter\n 1. At Front.\n 2. At End.\n 3. At Index.\n");
                printf("\n------------------------------------------\n");
                scanf("%d",&m);
                printf("\n------------------------------------------\n");
                switch(m)
                {
                    case 1: insertatFront(data);
                            break;
                    case 2: insertatEnd(data);
                            break;
                    case 3: printf("Enter the index you want to add:\t");
                            scanf("%d",&j);
                            printf("\n-------------------------------\n");
                            insertatIndex(data,j);
                            break;
                    default: printf("Invalid Choice");
                             printf("\n------------------------------------------\n");
                }
                break;
        case 2: printf("Enter\n 1. At Front.\n 2. At End.\n 3. At Index\n");
                printf("\n------------------------------------------\n");
                scanf("%d",&m);
                switch(m)
                {
                    case 1: deleteatFront();
                            break;
                    case 2: deleteatEnd();
                            break;
                    case 3: printf("Enter the index you want to delete node:\t ");
                            scanf("%d",&g);
                            deleteatIndex(g);
                            break;
                    default: printf("Invalid choice.");
                             printf("\n------------------------------------------\n");
                }
                break;
        case 3: display();
                break;
        case 4: displayBack();
                break;
        case 5: printf("The program is Terminated.\n You Can close the terminal now.");
                exit(0);
                break;
        default: printf("Invalid choice.");
                  printf("\n------------------------------------------\n");
    }
    }
}