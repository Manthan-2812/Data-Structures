// Linked Representation =>
#include<stdio.h>
#include<stdlib.h>

// Blue print of doubly node =>
struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};
struct Node * n;
// Creating Node ->
struct Node * createNode(int info);
struct Node * createNode(int info)
{
    n = (struct Node*) malloc(sizeof(struct Node));
    n->data = info;
    n->left = NULL; // set left pointer to null
    n->right = NULL; // set right pointer to null
    return n;
}

// PreOrder Traversal =>
void preOrder(struct Node * root);
void preOrder(struct Node * root)
{
    if (root == NULL)
    {
        return;
    }
    if(root != NULL)
    {
        printf("%d\t",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node * root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        inOrder(root->left); // Visits all left node first.
        printf("%d\t",root->data); // then prints its root once root ==  NULL
        inOrder(root->right); // finally visits right node .
    }
}

// PostOrder Traversal =>
void postOrder(struct Node * root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\t",root->data);
    }
}

// Making of Binary search Tree =>
struct Node * BST(struct Node * root,int info)
{
    if(root == NULL)
    {
        return createNode(info);
    }
    else if(info<root->data)
    {
        root->left = BST(root->left,info);
    }
    else
    {
        root -> right = BST(root->right,info);
    }
    return root;
}

void main()
{

    int ch,data,n;
    struct Node * root = NULL; // initially the Tree is empty , so the root is null.
    do
    {
         printf("Enter\n 1.Enter Element to tree.\n 2.Display Traversal.\n 3.exit.");
         printf("\n-------------------------------------------------------\n");
         scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the Element:\t");
                    scanf("%d",&data);
                    printf("\n-------------------------------------------------------\n");
                    root = BST(root,data);
                    break;
            case 2: printf("Enter 1.Preorder Traversal.\n 2.Inorder Traversal.\n 3.Postorder Traversal\n 4. Display all.\n");
                    scanf("%d",&n);
                    printf("\n-------------------------------------------------------\n");
                    switch(n)
                    {
                        case 1: printf("PreOrder Traversal :\t");
                                preOrder(root);
                                printf("\n-------------------------------------------------------\n");
                                break;
                        case 2: printf("Inorder Traversal :\t");
                                inOrder(root);
                                printf("\n-------------------------------------------------------\n");
                                break;
                        case 3: printf("PostOrder traversal :\t");
                                postOrder(root);
                                printf("\n-------------------------------------------------------\n");
                                break;
                        case 4: printf("All Traversals:\n");
                                printf("PreOrder Traversal :\t");
                                preOrder(root);
                                printf("\n-------------------------------------------------------\n");
                                printf("Inorder Traversal :\t");
                                inOrder(root);
                                printf("\n-------------------------------------------------------\n");
                                printf("PostOrder traversal :\t");
                                postOrder(root);
                                printf("\n-------------------------------------------------------\n");
                                break;
                    }
                    break;
            case 3: printf("Program Khatam. Jao Ghar pe.");
                    exit(0);
                    break;
            default: printf("Invalid Choice. Enter again\n");
                     printf("\n-------------------------------------------------------\n");
                     break;

        }
    } while (ch != 3);
    
}