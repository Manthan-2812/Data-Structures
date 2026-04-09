#include <stdio.h>
#include <math.h>

// Function to return maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to return minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Minimax function
int minimax(int depth, int nodeIndex, int isMax, int values[], int height) {
    
    // Base case: leaf node reached
    if (depth == height)
        return values[nodeIndex];

    // If MAX player's turn
    if (isMax)
        return max(
            minimax(depth + 1, nodeIndex * 2, 0, values, height),
            minimax(depth + 1, nodeIndex * 2 + 1, 0, values, height)
        );

    // If MIN player's turn
    else
        return min(
            minimax(depth + 1, nodeIndex * 2, 1, values, height),
            minimax(depth + 1, nodeIndex * 2 + 1, 1, values, height)
        );
}

int main() {
    int values[] = {3, 5, 2, 9, 12, 5, 23, 23}; // leaf nodes
    int n = sizeof(values) / sizeof(values[0]);

    int height = log2(n);

    int result = minimax(0, 0, 1, values, height);

    printf("The optimal value at root (MAX) is: %d\n", result);
    printf("The leaf nodes are :\n");
    for(int i = 0;i<8;i++)
    {
        printf("%d\t",values[i]);
    }

    return 0;
}