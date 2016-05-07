
#include <unistd.h>

extern void sleep(int);
extern void printArray (int* a,int size);

void bubble_sort_asc(int a[],int size)
{
    int tmp,i,j;

    for (i=0;i<size;i++)
    {
    for (j=0;j<size-1-i;j++)
    {
        if (a[j] > a[j+1])
        {
            tmp = a[j];
            a[j] = a[j+1];
            a[j+1] = tmp;
        }

        sleep(1);
        printf("While in operation:");
        printArray(a,9);

    }
    }


}
