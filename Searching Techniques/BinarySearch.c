#include <stdio.h>
#define max 50

int array[max];

void binarySearch(int n, int key) {
    int low = 0, high = n - 1, mid;
    int found = 0;

    printf("\n--- Binary Search Process ---\n");
    while (low <= high) {
        mid = (low + high) / 2;
        if (array[mid] == key) {
            printf("Element %d found at index %d\n", key, mid);
            found = 1;
            break;
        } else if (array[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("Element not found in the array.");
    }
    printf("\n----------------------------\n");
}

int main() {
    int n, key;
    printf("Enter size of sorted array: ");
    scanf("%d", &n);
    printf("Enter elements in sorted order: \n");
    for (int i = 0; i < n; i++) scanf("%d", &array[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);
    binarySearch(n, key);
    return 0;
}
