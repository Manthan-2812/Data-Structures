// Cirular Doubly Linked List =>
#include <stdio.h>
#include <stdlib.h>

// Create Node for Circular Doubly Linked List
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *node, *list = NULL, *last = NULL, *temp, *p; // Declared globally
int count = 0;

// Function to create a new node
struct Node *createNode(int info);
struct Node *createNode(int info)
{
    struct Node *nodes = (struct Node *)malloc(sizeof(struct Node));
    if (nodes == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    nodes->data = info;
    nodes->next = nodes; // Point to itself initially
    nodes->prev = nodes; // Point to itself initially
    return nodes;
}

// Function to insert node at front
void insertatFront(int info);
void insertatFront(int info)
{
    node = createNode(info);
    if(list == NULL)
    {
        list = node;
        last = node;
    }
    else
    {
        node->next = list;
        node->prev = last;
        list->prev = node;
        last->next = node;
        list = node;
    }
    count ++;
}

// Insert at Back =>
void insertatEnd(int info);
void insertatEnd(int info)
{
    node = createNode(info);
    if(list == NULL)
    {
        list = node;
        last = node;
    }
    else
    {
        node->next = list;
        last->next = node;
        node->prev = last;
        list->prev = node;
        last = node;
    }
    count++;
}

// Insert at Index =>
void insertatIndex(int info,int i);
void insertatIndex(int info,int i)
{
    node = createNode(info);
    if(i<1 || i>count+1)
    {
        printf("Inavlid Index. Enter again.");
        printf("\n------------------------------------------------------\n");
    }
    if(i == count+1)
    {
        insertatEnd(info);
    }
    if(i == 1)
    {
        insertatFront(info);
    }
    else
    {
        temp = list;
        for(int j = 1;j<i-1;j++)
        {
            temp = temp -> next;
        }
        p = temp->next;
        node->next = temp->next;
        node->prev = temp;
        p->prev = node;
        temp->next = node;
        free(temp);
    }
    count++;
}

// delete at front =>
void deleteatFront();
void deleteatFront()
{
    if(list == NULL)
    {
        printf("The list is empty.");
        printf("\n------------------------------------------------------\n");
    }
    else if(list -> next == NULL)
    {
        p = list;
        printf("The Deleted Node is:\t%d",p->data);
        printf("\n The list is now empty.");
        printf("\n------------------------------------------------------\n");
        list = NULL;
        last = NULL;
        free(p);
        count--;
    }
    else
    {
        temp = list;
        list = list->next;
        list->prev = last;
        last->next = list;
        printf("The Deleted element is:\t%d",temp->data);
        free(temp);
        count--;
    }
}

// delete at End =>
void deleteatEnd();
void deleteatEnd()
{
     if(list == NULL)
    {
        printf("The list is empty.");
        printf("\n------------------------------------------------------\n");
    }
    else if(list -> next == NULL)
    {
        p = list;
        printf("The Deleted Node is:\t%d",p->data);
        printf("\n The list is now empty.");
        printf("\n------------------------------------------------------\n");
        list = NULL;
        last = NULL;
        free(p);
        count--;
    }
    else
    {
        temp = last;
        last = last->prev; // ye pointer ko shift karga .
        last->next = list; // ye point karega.
        list -> prev = last ;
        printf("The Deleted Node is:\t%d",temp->data);
        free(temp);
        count--;
    }
}

// delete at Index => 
void deleteatIndex(int i);
void deleteatIndex(int i)
{
    if(i<1 || i>count+1)
    {
        printf("Inavlid Index.");
        printf("\n------------------------------------------------------\n");
    }
    else if(i == 1)
    {
        deleteatFront();
    }
    else if(i == count+1)
    {
        deleteatEnd();
    }
    else
    {
        temp = list;
        for(int j = 0;j<i;j++)
        {
            temp = temp -> next;
        }
        p = temp; // isme temp woh node pe rukega jo node hame nikalna hai.
        //temp->next = temp -> prev;
        (temp->prev)->next = temp -> next;
        (temp->next)->prev = temp -> prev;
        printf("The Deleted Element is:\t%d",p->data);
        printf("\n------------------------------------------------------\n");
        free(p);
        count--;
    }
}

// Forward display =>
void displayForward() {
    if(list == NULL) 
    {
        printf("List is empty!\n");
        return;
    }
    
    printf("List in forward direction:\n");
    temp = list;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while(temp != list);
    printf("Total nodes: %d\n", count);
    printf("\n------------------------------------------------------\n");
}

// Function to display list in backward direction
void displayBackward() 
{
    if(list == NULL) 
    {
        printf("List is empty!\n");
        return;
    }
    
    printf("List in backward direction:\n");
    temp = last;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    } while(temp != last);
    printf("Total nodes: %d\n", count);
    printf("\n------------------------------------------------------\n");
}

// Main function =>
void main()
{
    int data,n,m;
    while(n != 4)
    {
        printf("Enter\n 1.Insert.\n 2.Delete.\n 3.Display the List.\n 4.Exit.");
        printf("\n------------------------------------------\n");
        scanf("%d",&n);
        printf("\n------------------------------------------\n");
        switch(n)
        {
            case 1: printf("Enter\n 1.Insert at Front.\n 2.Insert at End.\n 3.Insert at Index.");
                    printf("\n------------------------------------------\n");
                    scanf("%d",&m);
                    printf("\n------------------------------------------\n");
                    switch(m)
                    {
                        case 1: printf("Enter the Element:\t");
                                scanf("%d",&data);
                                printf("\n------------------------------------------\n");
                                insertatFront(data);
                                break;
                        case 2: printf("Enter the Element:\t");
                                scanf("%d",&data);
                                printf("\n------------------------------------------\n");
                                insertatEnd(data);
                                break;
                        case 3: printf("Enter the Element:\t");
                                scanf("%d",&data);
                                printf("\n------------------------------------------\n");
                                printf("Enter index:\t");
                                scanf("%d",&m);
                                insertatIndex(data,m);
                                break;
                        default: printf("Invalid choice.");
                                 printf("\n------------------------------------------\n");
                                 break;
                    }
                    break;
            case 2: printf("Enter\n 1.Delete at Front.\n 2.Delete at End.\n 3.Delete at Index.");
                    printf("\n------------------------------------------\n");
                    scanf("%d",&m);
                    printf("\n------------------------------------------\n");
                    switch(m)
                    {
                        case 1: deleteatFront();
                                break;
                        case 2: deleteatEnd();
                                break;
                        case 3: printf("Enter index:\t");
                                scanf("%d",&m);
                                deleteatIndex(m);
                                break;
                        default: printf("Invalid choice.");
                                 printf("\n------------------------------------------\n");
                                 break;
                    }
                    break;
            case 3: printf("Enter\n 1.Forward Display.\n 2.Backward Display.\n");
                    scanf("%d",&m);
                    printf("\n------------------------------------------\n");
                    switch(m)
                    {
                        case 1: displayForward();
                                break;
                        case 2: displayBackward();
                                break;
                        default: printf("Invalid choice.");
                                 printf("\n------------------------------------------\n");
                                 break;
                    }
                    break;
            case 4: printf("Program Terminated.\nYou can close the Terminal.");
                    exit(0);
                    break;
            default: printf("Invalid Operation. Enter choice again !");
                     printf("\n------------------------------------------\n");
                     break;
        }
    }
}