#include <stdio.h>
#define max 50

int array[max];

// Utility function to find minimum of two values
int min(int x, int y) { return (x <= y) ? x : y; }

void fibonacciSearch(int n, int key) {
    int m2 = 0;   // (m-2)'th Fibonacci No.
    int m1 = 1;   // (m-1)'th Fibonacci No.
    int m = m2 + m1; // m'th Fibonacci

    // Find smallest Fibonacci number >= n
    while (m < n) {
        m2 = m1;
        m1 = m;
        m = m2 + m1;
    }

    int offset = -1;
    int found = 0;

    printf("\n--- Fibonacci Search Process ---\n");
    while (m > 1) {
        int i = min(offset + m2, n - 1);

        if (array[i] < key) {
            m = m1;
            m1 = m2;
            m2 = m - m1;
            offset = i;
        } else if (array[i] > key) {
            m = m2;
            m1 = m1 - m2;
            m2 = m - m1;
        } else {
            printf("Element %d found at index %d\n", key, i);
            found = 1;
            break;
        }
    }

    // Comparing last element
    if (!found && m1 && array[offset + 1] == key) {
        printf("Element %d found at index %d\n", key, offset + 1);
        found = 1;
    }

    if (!found) printf("Element not found.");
    printf("\n----------------------------\n");
}

int main() {
    int n, key;
    printf("Enter size of sorted array: ");
    scanf("%d", &n);
    printf("Enter elements: \n");
    for (int i = 0; i < n; i++) scanf("%d", &array[i]);

    printf("Enter search key: ");
    scanf("%d", &key);
    fibonacciSearch(n, key);
    return 0;
}
