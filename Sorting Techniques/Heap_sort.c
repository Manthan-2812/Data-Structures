// Heapify(array, size, largest index)
#include<stdio.h>

void swap(int a[],int large,int last);
void swap(int a[],int large,int last)
{
    int temp;
    temp = a[last];
    a[last] = a[large];
    a[large] = temp;
}

void heapify(int a[],int size,int i); // i = largest
void heapify(int a[],int size,int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<size && a[left]>a[largest])
    {
        largest = left;
    }
    if(right<size && a[right]>a[largest]) // Isme jo largest hai woh updated vala hai jo left vala index se exchange huva hai.
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(a,largest,i);
        heapify(a,size,largest);
    }
}

void heap_sort(int a[],int size);
void heap_sort(int a[],int size)
{
    //Heapify initial array of elements before sort.
    for(int i=((size/2)-1);i>=0;i--)
    {
        heapify(a,size,i);
    }

    for(int j = size-1;j>=1;j--)
    {
        swap(a,0,j);
        heapify(a,j,0);
    }

}

void main()
{
    int n;
    printf("Enter the size of array:\t ");
    scanf("%d",&n);
    printf("\n");
    int a[n],i;
    printf("Enter the elements in array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n");
    printf("Intitial Unsorted array:\n");
     for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    heap_sort(a,n);
    printf("The final array by heap sort is:\n");
    for(int k = 0;k<n;k++)
    {
        printf("%d\t",a[k]);
    }
    printf("\n-------------------------------------\n");
    
}