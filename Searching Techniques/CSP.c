#include <stdio.h>

#define N 4  // Number of regions

// Check if it's safe to assign color
int isSafe(int node, int graph[N][N], int color[], int c) {
    for (int i = 0; i < N; i++) {
        if (graph[node][i] && color[i] == c)
            return 0;
    }
    return 1;
}

// Backtracking function
int solveCSP(int graph[N][N], int m, int color[], int node) {
    
    // If all nodes are colored
    if (node == N)
        return 1;

    // Try different colors
    for (int c = 1; c <= m; c++) {
        
        if (isSafe(node, graph, color, c)) {
            color[node] = c;

            // Recur for next node
            if (solveCSP(graph, m, color, node + 1))
                return 1;

            // Backtrack
            color[node] = 0;
        }
    }

    return 0;
}

// Print solution
void printSolution(int color[]) {
    printf("Solution (Region : Color):\n");
    for (int i = 0; i < N; i++) {
        printf("Region %d -> Color %d\n", i, color[i]);
    }
}

// Driver Code
int main() {

    // Adjacency matrix
    int graph[N][N] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // Number of colors
    int color[N] = {0};

    if (solveCSP(graph, m, color, 0))
        printSolution(color);
    else
        printf("No solution exists\n");

    return 0;
}