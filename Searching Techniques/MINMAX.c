#include <stdio.h>
#include <math.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}


int min(int a, int b) {
    return (a < b) ? a : b;
}

// Minimax function
int minimax(int depth, int nodeIndex, int isMax, int values[], int height) {
    
    
    if (depth == height)
        return values[nodeIndex];

    
    if (isMax)
        return max(
            minimax(depth + 1, nodeIndex * 2, 0, values, height),
            minimax(depth + 1, nodeIndex * 2 + 1, 0, values, height)
        );

    
    else
        return min(
            minimax(depth + 1, nodeIndex * 2, 1, values, height),
            minimax(depth + 1, nodeIndex * 2 + 1, 1, values, height)
        );
}

int main() { // leaf nodes
    int n;
    
    printf("Enter the number of leaf nodes:\t");
    scanf("%d",&n);
    if ((n & (n - 1)) != 0) {
    printf("Number of leaf nodes must be a power of 2!\n");
    return 0;
}
    int values[n];
    printf("Enter the leaf node values:\t");

    for(int j=0 ;j<n;j++)
    {
        scanf("%d",&values[j]);
    }
    

    int height = log2(n);
    

    int result = minimax(0, 0, 1, values, height);

    printf("The optimal value at root (MAX) is: %d\n", result);
    printf("The leaf nodes are :\n");
    for(int i = 0;i<n;i++)
    {
        printf("%d\t",values[i]);
    }

    return 0;
}