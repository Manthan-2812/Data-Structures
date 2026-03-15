#include <stdio.h>

// Function definition
int f(int x)
{
    return -x*x + 6*x + 5;
}

int hillClimbing(int start)
{
    int current = start;
    int neighbor;

    while (1)
    {
        neighbor = current + 1;

        // If neighbor gives better value, move there
        if (f(neighbor) > f(current))
        {
            current = neighbor;
        }
        else
        {
            break; // stop when no better neighbor
        }
    }

    return current;
}

int main()
{
    int start;

    printf("Enter starting value of x: ");
    scanf("%d", &start);

    int max_x = hillClimbing(start);

    printf("\nMaximum value found at x = %d\n", max_x);
    printf("Maximum value of function f(x) = %d\n", f(max_x));

    return 0;
}