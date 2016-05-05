#include <unistd.h>

void selection_sort(int a[],int size)
{
    int k=0,j=0,min=0,tmp;
    for (k=0;k<size-1;k++)
    {
        min=k;
        for (j=k+1;j<size;j++)
        {
            if (a[min] > a[j])
            {
                min=j;
            }
        }
        if (min != k)
        {
            tmp = a[min];
            a[min] = a[k];
            a[k] = tmp;
        }
        printf("While in operation(k=%d): ",k);
        printArray(a,size);
        sleep(1);
    }
}
