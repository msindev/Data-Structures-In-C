#include <stdio.h>
#include <stdlib.h>
int count;
void quicksort(int[], int, int);
int partition(int[], int, int);
int main()
{
    int a[1200],b[1200],c[1200],c1,c2,c3,i,j,n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i = 0; i < n; i++)
        scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    printf("Sorted Array:");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\nTime Complexity Analysis: \n");
    printf("SIZE\tASCENDING\tDESCENDING\tRANDOM\n");
    for(i=16;i<=1024;i*=2)
    {
        for(j=0;j<i;j++)
        {
            a[j]=j;
            b[j]=i-j;
            c[j]=rand()%(i+1);
        }
        count = 0;
        quicksort(a,0,i-1);
        c1=count;
        count=0;
        quicksort(b,0,i-1);
        c2=count;
        count=0;
        quicksort(c,0,i-1);
        c3=count;
        printf("%d\t%d\t\t%d\t\t%d\n",i,c1,c2,c3);
    }
    return 0;
}
void quicksort(int a[], int low, int high)
{
    int j;
    if(low<high)
    {
        j=partition(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}

int partition(int a[], int low, int high)
{
    int p;
    p = a[low];
    int i = low+1, j = high, temp;
    while(1)
    {
        while(a[i] < p && i <= high)
        {
            i++;
            count++;
        }
        count++;
        while(a[j]>=p && j>low)
        {
            j--;
            count++;
        }
        count++;
        if(i<j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
        {
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        }
    }
}
