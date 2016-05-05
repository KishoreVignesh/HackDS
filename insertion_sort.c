
#include <unistd.h>

void insertion_sort(int a[],int size)
{
    int i=0,j=0,tmp=0;
    for (;i<size;i++)
    {
        j=i-1;
        while (j>=0)
        {
            if ( a[j] > a[j+1])
            {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
            else
            {

                break;
            }
            j--;
            printf("While operation: ");
            printArray(a,size);
            sleep(1);
        }
    }
}
