//Declaration
#ifdef _WIN32
#include <windows.h>

void sleep(int time)
{
    Sleep(time *1000);
}


#endif

extern void bubble_sort_asc(int a[],int size);
extern void insertion_sort(int a[],int size);
extern void selection_sort(int a[],int size);
extern void quick_sort (int a[],int low,int high,int size);
extern void merge_sort (int a[],int low,int high,int size);

void printArray (int* a,int size)
{
    int i=0;
    printf("\t[");
    for (;i<size;i++)
    {
        printf(" %d ",a[i]);
        if (i!=size-1)
        {
            printf(",");
        }
    }
    printf("]\n");
}

void testBubbleSort(int a[],int size){

    printf("Testing Bubble Sort ascending order:\n");

    printf("Before Bubble sort ascending:");
    printArray(a,size);

    bubble_sort_asc(a,size);
    printf("After Bubble sort ascending:");
    printArray(a,size);

}

void testInsertionSort(int a[],int size){

    printf("Testing Insertion Sort ascending order:\n");

    printf("Before Insertion sort ascending:");
    printArray(a,size);

    insertion_sort(a,size);
    printf("After Insertion sort ascending:");
    printArray(a,size);

}

void testSelectionSort(int a[],int size){

    printf("Testing Selection Sort ascending order:\n");

    printf("Before Selection sort ascending:");
    printArray(a,size);

    selection_sort(a,size);
    printf("After Selection sort ascending:");
    printArray(a,size);

}

void testQuickSort(int a[],int low,int high,int size){

    printf("Testing Quick Sort ascending order:\n");

    printf("Before Quick sort ascending:");
    printArray(a,size);

    quick_sort(a,low,high,size);
    printf("After Quick sort ascending:");
    printArray(a,size);

}

void testMergeSort(int a[],int low,int high,int size){

    printf("Testing Merge Sort ascending order:\n");

    printf("Before Merge sort ascending:");
    printArray(a,size);

    merge_sort(a,low,high,size);
    printf("After Merge sort ascending:");
    printArray(a,size);

}
