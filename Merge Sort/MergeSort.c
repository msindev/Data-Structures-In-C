#include <stdio.h>
#include <stdlib.h>
int count;
void mergesort(int[], int, int);
void merge(int[], int, int, int);
int main()
{
    int a[1200],b[1200],c[1200],c1,c2,c3,i,j,n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i = 0; i < n; i++)
        scanf("%d",&a[i]);
    mergesort(a,0,n-1);
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
        mergesort(a,0,i-1);
        c1=count;
        count=0;
        mergesort(b,0,i-1);
        c2=count;
        count=0;
        mergesort(c,0,i-1);
        c3=count;
        printf("%d\t%d\t\t%d\t\t%d\n",i,c1,c2,c3);
    }
    return 0;
}

void mergesort(int a[], int low, int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void merge(int a[], int low, int mid, int high)
{
    int b[1200],i=low,j=mid+1,k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
        count++;
    }
    while(i<=mid)
    {
        b[k++]=a[i++];
        count++;
    }
    while(j<=high)
    {
        b[k++]=a[j++];
        count++;
    }
    for(k=low;k<=high;k++)
        a[k]=b[k];
}
