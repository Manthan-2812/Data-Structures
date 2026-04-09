#include <stdio.h>

#define MAX 1000
#define MIN -1000

// Function to return maximum
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to return minimum
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Minimax with Alpha-Beta Pruning
int minimax(int depth, int nodeIndex, int maximizingPlayer,
            int values[], int alpha, int beta) {
    
    // Leaf node condition
    if (depth == 3)
        return values[nodeIndex];

    if (maximizingPlayer) {
        int best = MIN;

        for (int i = 0; i < 2; i++) {
            int val = minimax(depth + 1, nodeIndex * 2 + i,
                              0, values, alpha, beta);

            best = max(best, val);
            alpha = max(alpha, best);

            // Alpha-Beta Pruning
            if (beta <= alpha)
                break;
        }
        return best;
    } else {
        int best = MAX;

        for (int i = 0; i < 2; i++) {
            int val = minimax(depth + 1, nodeIndex * 2 + i,
                              1, values, alpha, beta);

            best = min(best, val);
            beta = min(beta, best);

            // Alpha-Beta Pruning
            if (beta <= alpha)
                break;
        }
        return best;
    }
}

// Driver Code
int main() {
    int values[8] = {3, 5, 6, 9, 1, 2, 0, -1};

    int result = minimax(0, 0, 1, values, MIN, MAX);

    printf("The leaf nodes are :\n");
    for(int i = 0;i<8;i++)
    {
        printf("%d\t",values[i]);
    }

    printf("\nThe optimal value is: %d\n", result);

    return 0;
}