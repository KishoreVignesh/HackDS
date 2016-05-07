
#include <unistd.h>

int partition_quick_sort(int a[],int low,int high,int size);

void quick_sort (int a[],int low,int high,int size)
{
    int m=0;
    if (low<high)
    {
        m=partition_quick_sort(a,low,high,size);
        quick_sort(a,low,m-1,size);
        quick_sort(a,m+1,high,size);
    }
}

int partition_quick_sort(int a[],int low,int high,int size)
{
    int k=low, pivot=a[high],i=0,temp=0;
    for ( i=low ; i<high ; i++ )
    {
        if( a[i] <= pivot )
        {
            temp=a[k];
            a[k]=a[i];
            a[i]=temp;
            k++;
            printf("While operation: ");
            printArray(a,size);
            sleep(1);
        }
    }
    a[high]=a[k];
    a[k]=pivot;
    printf("While operation: ");
    printArray(a,size);
    sleep(1);
    return k;
}
