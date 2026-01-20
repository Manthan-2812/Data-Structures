#include <stdio.h>

#define max 50
int array[max];

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to find the pivot index
int partition(int low, int high) {
    int pivot = array[low]; // Choosing first element as pivot (Your style)
    int i = low;
    int j = high;

    while (i < j) {
        // Increment i while elements are less than or equal to pivot
        while (array[i] <= pivot && i <= high - 1) {
            i++;
        }
        // Decrement j while elements are greater than pivot
        while (array[j] > pivot && j >= low + 1) {
            j--;
        }
        
        if (i < j) {
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[low], &array[j]); // Put pivot in its correct sorted place
    return j; // Return the partition index
}

// Recursive function for Quick Sort
void quickSort(int low, int high) {
    if (low < high) {
        int partitionIndex = partition(low, high);
        
        // Separately sort elements before and after partition
        quickSort(low, partitionIndex - 1);
        quickSort(partitionIndex + 1, high);
    }
}

void main() {
    int n, i;
    
    printf("Enter number of elements (max 50): ");
    scanf("%d", &n);
    
    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    
    printf("\n--- Original Array ---\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    quickSort(0, n - 1);

    printf("\n\n--- Sorted Array (Quick Sort) ---\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n------------------------\n");
}
