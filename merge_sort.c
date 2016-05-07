
#include <unistd.h>
void merge(int a[],int low,int m,int high, int size);

void merge_sort (int a[],int low,int high,int size)
{
    int m;
    if (low<high)
    {
        m= (low+high)/2;

        merge_sort(a,low,m,size);
        merge_sort(a,m+1,high,size);
        merge(a,low,m,high,size);
    }
}

void merge(int a[],int low,int m,int high, int size)
{
    int tmp[size],k=low,i=low,j=m+1,l=0;

    while(i<(m+1) && j<=high)
    {
        if (a[i] < a[j])
        {
            tmp[k++]=a[i++];
        }
        else
        {
            tmp[k++]=a[j++];
        }
    }

    while(i<(m+1))
    {
        tmp[k++]=a[i++];
    }

    while(j<=high)
    {
        tmp[k++]=a[j++];
    }

    for(l=low;l<=high;l++)
    {
        a[l]=tmp[l];
    }
    printf("While operation: ");
    printArray(a,size);
    sleep(1);
}
