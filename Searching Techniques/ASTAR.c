#include <stdio.h>
#include <limits.h>

#define MAX 20
#define INF 99999

int graph[MAX][MAX];
int heuristic[MAX];
int n;

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

        // Find node with minimum f value
        int bestIndex = 0;
        for (int i = 1; i < openCount; i++)
            if (f[open[i]] < f[open[bestIndex]])
                bestIndex = i;

        int current = open[bestIndex];

        // Remove from open list
        open[bestIndex] = open[--openCount];
        closed[current] = 1;

        // Goal reached
        if (current == goal) {
            printf("\nShortest Path: ");
            printPath(parent, goal);
            printf("\nTotal Path Cost: %d\n", g[goal]);
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

                    // Add to open if not present
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

    int edges;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Initialize graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source destination cost):\n");
    for (int i = 0; i < edges; i++) {
        int u, v, cost;
        scanf("%d %d %d", &u, &v, &cost);
        graph[u][v] = cost;
        graph[v][u] = cost;  
    }

    printf("Enter heuristic values for each node:\n");
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