# include<stdio.h>
# define SIZE 100

void merge_sort(int a[],int lb, int mid,int ub);
void merge_sort(int a[],int lb, int mid,int ub)
{
    int i = lb,k = lb,j = mid+1,b[SIZE];
    while(i <=mid && j<=ub)
    {
        if(a[i]<=a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for(i=lb;i<=ub;i++)
    {
		a[i]=b[i];
    }
}

void merge_split(int a[],int lb,int ub);
void merge_split(int a[],int lb,int ub)
{
    int mid;
    if(lb<ub) // This is the base condition for recursive call as 
    {
        mid = (lb+ub)/2;
        merge_split(a,lb,mid);
        merge_split(a,mid+1,ub);
        merge_sort(a,lb,mid,ub);
    }

}
void main ()
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
    int lb = 0;
    int ub = n-1;
    merge_split(a,lb,ub);
    printf("\nThe sorted array is as follows:\n");
        for(int i=lb;i<=ub;i++)
        {
        printf("%d\t",a[i]);
        }
        printf("\n-------------------------------------\n");
}