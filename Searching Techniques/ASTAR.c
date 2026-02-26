#include <stdio.h>
#include <limits.h>

#define MAX 10
#define INF 9999

int graph[MAX][MAX];
int heuristic[MAX];
int n;   // number of nodes

// Function to print path
void printPath(int parent[], int goal) {
    if (parent[goal] == -1) {
        printf("%d ", goal);
        return;
    }
    printPath(parent, parent[goal]);
    printf("%d ", goal);
}

void aStar(int start, int goal) {

    int open[MAX], closed[MAX] = {0};
    int g[MAX], f[MAX], parent[MAX];
    int openCount = 0;

    for (int i = 0; i < n; i++) {
        g[i] = INF;
        f[i] = INF;
        parent[i] = -1;
    }

    g[start] = 0;
    f[start] = heuristic[start];
    open[openCount++] = start;

    while (openCount > 0) {

        // Find node with minimum f
        int bestIndex = 0;
        for (int i = 1; i < openCount; i++)
            if (f[open[i]] < f[open[bestIndex]])
                bestIndex = i;

        int current = open[bestIndex];

        // Remove from open
        open[bestIndex] = open[--openCount];
        closed[current] = 1;

        if (current == goal) {
            printf("\nShortest Path: ");
            printPath(parent, goal);
            printf("\nTotal Cost: %d\n", g[goal]);
            return;
        }

        // Check neighbors
        for (int i = 0; i < n; i++) {
            if (graph[current][i] > 0 && !closed[i]) {

                int tempG = g[current] + graph[current][i];

                if (tempG < g[i]) {
                    g[i] = tempG;
                    f[i] = g[i] + heuristic[i];
                    parent[i] = current;

                    // Add to open if not already present
                    int found = 0;
                    for (int j = 0; j < openCount; j++)
                        if (open[j] == i) found = 1;

                    if (!found)
                        open[openCount++] = i;
                }
            }
        }
    }

    printf("No path found.\n");
}

int main() {

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter heuristic values:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &heuristic[i]);

    int start, goal;
    printf("Enter start node: ");
    scanf("%d", &start);

    printf("Enter goal node: ");
    scanf("%d", &goal);

    aStar(start, goal);

    return 0;
}