// Circular Singly Linked List =>
# include<stdio.h>
# include<stdlib.h>
  
// Create Node =>
struct Node
{
    int data;
    struct Node * next;
};

struct Node * node,*list = NULL,*last = NULL,*temp,*p; // Declared globally
int count = 0;

struct Node * createNode(int info);
struct Node * createNode(int info)
{
    struct Node * nodes = (struct Node*)malloc(sizeof(struct Node)); // Declared locally
    nodes -> data = info;
    nodes -> next = NULL;
    return nodes;
}

// inserting node at front =>
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
        list = node;
        last->next=list; // Last pointer ka jo next address variable hai usme ye naya node ka address store ho jaega.
    }
    count++;
}

// Inserting Node at Back =>
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
        last->next = node;
        last = node;
        last->next = list;
    }
    count++;
}

// Insert at index =>
void insertatIndex(int info,int n);
void insertatIndex(int info, int n)
{
      node = createNode(info);
    if(n > count+1 || n<1)
    {
        printf("Cannot insert beyond available nodes.");
    }
    else if(n == 1)
    {
        insertatFront(info);

    }
    else if(n == count + 1)
    {
        insertatEnd(info);

    }
    else
    {
            temp = list;
        for(int i = 1;i<n-1;i++) // Loop Runs till n-1 where n -1 is not included.
        {
           // p = temp;
            temp = temp ->next;
        }
        node->next = temp->next; // now wherever the loop stooped at a node its next address which is the insertion index we want is assigned to the new node's next address
        // So now the n-1 th node which had stored the address of nth node is now free and now we shall connect its next address pointer to new node pointer address.
        temp->next = node;
        count++; // Node Successfully added .
    }
}

// Delete at Front
void deleteatFront();
void deleteatFront()
{
    if(list == NULL)
    {
        printf("The List is already empty.");
        printf("\n------------------------------------------\n");
    }
    else
    {
        temp = list;
        list = list->next;
        printf("The Deleted Element is\t%d",temp->data);
        printf("\n------------------------------------------\n");
        free(temp);
        last -> next = list; // !! after deleting the node ,make sure to adjust last pointer pointing to the list. Updting it .
        count--;
    }
}

// delete at end =>
void deleteatEnd();
void deleteatEnd()
{
   if(list == NULL)
    {
        printf("The List is already empty.");
        printf("\n------------------------------------------\n");
    }
    else if (list->next == NULL)  // only one node
    {
        printf("The Deleted Element was :\t%d\n", list->data);
        printf("\n------------------------------------------\n");
        free(list);
        list = last = NULL;
        count--;
    }
    else
    {
        temp = list;
        while(temp->next != last)
        {
            temp = temp -> next;
        }
        p = temp -> next;
        printf("The Deleted Element was :\t%d",p->data);
        printf("\n------------------------------------------\n");
        free(p);
        last = temp;
        last -> next = list;
        count --;
    }
}

// Delete at Index =>
void deleteatIndex(int j);
void deleteatIndex(int j)
{
     if(list == NULL)
    {
        printf("The List is already empty.");
        printf("\n------------------------------------------\n");
    }
    if(j<1 || j>count+1)
    {
        printf("Invalid Index Entered.");
        printf("\n------------------------------------------\n");
    }
    else if(j == 1)
    {
        deleteatFront();
    }
    else if(j == count)
    {
        deleteatEnd();
    }
    else
    {
        temp = list;
        for(int i = 1;i<j-1;i++)
        {
            temp = temp ->next;
        } // temp (n-1)th node pe rukega.
        p = temp->next; // after exiting the loop , temp next address i.e the addrress of the node which we want to delete is stored in p pointer variable.
        printf("The Deleted Element was :\t%d",p->data);
        printf("\n------------------------------------------\n");
        temp -> next = p -> next; // temp which is stopped at  (n-1)th node will now point its next node address after p.
        free(p);
        count--;
    }
}

// display function =>
void display();
void display()
{
    if(list == NULL)
    {
        printf("The List is already empty.");
        printf("\n------------------------------------------\n");
    }
    printf("The Linked list is :\n");
    if(list -> next == NULL) // for only one node.
    {
        printf("%d",list->data);
        printf("The Total Number of Nodes:\t%d",count);
        printf("\n------------------------------------------\n");
    }
    else
    {
        temp = list;
        do
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }while(temp != list);
        printf("\nThe Total Number of Nodes:\t%d",count);
        printf("\n------------------------------------------\n");
    }

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
            case 3: display();
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