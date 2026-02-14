#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_NODES 100
#define MAX_QUEUE_SIZE 1000
// Structure to represent a node in the graph (for adjacency list)
typedef struct Node {
    int dest;
    int cost;
    struct Node* next;
} Node;
// Structure to represent a state in the priority queue
typedef struct State {
    int node_id;
    int current_cost;
    int parent_id; // To reconstruct the path
} State;
// Array-based "priority queue" - we will keep it sorted manually
State priority_queue[MAX_QUEUE_SIZE];
int pq_size = 0;
// Function to add a state to the priority queue and maintain sort order (ascending cost)
void enqueue(State new_state) {
    if (pq_size >= MAX_QUEUE_SIZE) {
        printf("Priority queue overflow\n");
        return;
    }
    priority_queue[pq_size] = new_state;
    pq_size++;
    // Manually sort the array to simulate a min-priority queue (bubble sort style, inefficient but works without a heap)
    for (int i = 0; i < pq_size - 1; i++) {
        for (int j = i + 1; j < pq_size; j++) {
            if (priority_queue[i].current_cost > priority_queue[j].current_cost) {
                State temp = priority_queue[i];
                priority_queue[i] = priority_queue[j];
                priority_queue[j] = temp;
            }
        }
    }
}
// Function to remove the state with the lowest cost from the priority queue
State dequeue() {
    // The lowest cost item is at the front of our manually sorted array
    State lowest_cost_state = priority_queue[0];
    // Shift elements to remove the first one
    for (int i = 0; i < pq_size - 1; i++) {
        priority_queue[i] = priority_queue[i + 1];
    }
    pq_size--;
    return lowest_cost_state;
}
// Function to check if the priority queue is empty
int is_pq_empty() {
    return pq_size == 0;
}
// Graph implementation using an adjacency list
Node* graph[MAX_NODES];
void add_edge(int src, int dest, int cost) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->dest = dest;
    new_node->cost = cost;
    new_node->next = graph[src];
    graph[src] = new_node;
}
// Function to print the path by backtracking
void print_path(int parent_map[], int goal_node, int start_node) {
    int path[MAX_NODES];
    int path_len = 0;
    int current = goal_node;
    while (current != start_node) {
        path[path_len++] = current;
        current = parent_map[current];
    }
    path[path_len++] = start_node;
    printf("Optimal Path: ");
    for (int i = path_len - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i > 0) printf(" -> ");
    }
    printf("\n");
}
// Uniform Cost Search function
void uniform_cost_search(int start, int goal, int num_nodes) {
    // parent_map array to store the parent of each node for path reconstruction
    int parent_map[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++) parent_map[i] = -1;
    // visited array to keep track of explored nodes
    int visited[MAX_NODES] = {0};
    // Initialize priority queue with the start node
    State initial_state = {start, 0, -1}; // Start node has no parent
    enqueue(initial_state);
    while (!is_pq_empty()) {
        State current_state = dequeue();
        int current_node = current_state.node_id;
        int current_cost = current_state.current_cost;
        // If the node has already been visited optimally, skip
        if (visited[current_node]) continue;
        visited[current_node] = 1;
        parent_map[current_node] = current_state.parent_id;
        // Check if goal is reached
        if (current_node == goal) {
            printf("Goal reached! Total cost: %d\n", current_cost);
            print_path(parent_map, goal, start);
            return;
        }
        // Expand the current node's neighbors
        Node* temp = graph[current_node];
        while (temp != NULL) {
            if (!visited[temp->dest]) {
                State new_state;
                new_state.node_id = temp->dest;
                new_state.current_cost = current_cost + temp->cost;
                new_state.parent_id = current_node; // Mark current as parent
                enqueue(new_state);
            }
            temp = temp->next;
        }
    }
    printf("Goal not reachable from start node.\n");
}
int main() {
    int num_nodes = 6; // Example number of nodes
    // Define the graph structure with costs
    // Example: Node 0 is Start, Node 5 is Goal
    add_edge(0, 1, 4);
    add_edge(0, 2, 2);
    add_edge(1, 3, 5);
    add_edge(1, 2, 1);
    add_edge(2, 3, 8);
    add_edge(2, 4, 10);
    add_edge(3, 4, 2);
    add_edge(3, 5, 6);
    add_edge(4, 5, 2);
    int start_node = 0;
    int goal_node = 5;
    printf("Starting Uniform Cost Search from node %d to node %d\n", start_node, goal_node);
    uniform_cost_search(start_node, goal_node, num_nodes);
    return 0;
}