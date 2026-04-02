#include <stdio.h>
#include <limits.h>

#define MAX 20
#define INF 99999

int graph[MAX][MAX];
int heuristic[MAX];
int n;

// Print path
void printPath(int parent[], int goal) {
    if (parent[goal] == -1) {
        printf("%d ", goal);
        return;
    }
    printPath(parent, parent[goal]);
    printf("%d ", goal);
}

void greedyBFS(int start, int goal) {

    int open[MAX], closed[MAX] = {0};
    int parent[MAX];
    int cost[MAX];
    int openCount = 0;

    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
        cost[i] = INF;
    }

    open[openCount++] = start;
    cost[start] = 0;

    while (openCount > 0) {

        // Select node with smallest heuristic
        int bestIndex = 0;
        for (int i = 1; i < openCount; i++)
            if (heuristic[open[i]] < heuristic[open[bestIndex]])
                bestIndex = i;

        int current = open[bestIndex];

        // Remove from OPEN
        open[bestIndex] = open[--openCount];
        closed[current] = 1;

        if (current == goal) {
            printf("\nPath: ");
            printPath(parent, goal);
            printf("\nTotal Cost: %d\n", cost[goal]);
            return;
        }

        // Explore neighbors
        for (int i = 1; i <= n; i++) {
            if (graph[current][i] > 0 && !closed[i]) {

                parent[i] = current;
                cost[i] = cost[current] + graph[current][i];

                // Add to open if not present
                int found = 0;
                for (int j = 0; j < openCount; j++)
                    if (open[j] == i) found = 1;

                if (!found)
                    open[openCount++] = i;
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
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source destination cost):\n");
    for (int i = 0; i < edges; i++) {
        int u, v, cost;
        scanf("%d %d %d", &u, &v, &cost);
        graph[u][v] = cost;
        graph[v][u] = cost;   // remove if directed
    }

    printf("Enter heuristic values (1 to %d):\n", n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &heuristic[i]);

    int start, goal;

    printf("Enter start node: ");
    scanf("%d", &start);

    printf("Enter goal node: ");
    scanf("%d", &goal);

    greedyBFS(start, goal);

    return 0;
}