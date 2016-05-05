#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.c"
#include <unistd.h>
#include "insertion_sort.c"
#include "selection_sort.c"
#include "quick_sort.c"
#include "merge_sort.c"

void printArray(int* a,int size)
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



int main()
{
    int a[9] = {9,8,1,4,2,5,3,6,7};
    int b[9] = {1,2,3,4,5,6,7,8,9};
    int o;


    //testBubbleSort(a,9);    // 36 seconds
    //testBubbleSort(b,9);    // 36 Seconds
    //testInsertionSort(a,9); // 17 seconds
    //testInsertionSort(b,9); // 0 seconds
    //testSelectionSort(a,9); // 08 seconds
    //testSelectionSort(b,9); // 08 seconds
    //testQuickSort(a,0,8,9); // 21 seconds
    //testQuickSort(b,0,8,9); // 44 seconds
    //testMergeSort(a,0,8,9); // 08 seconds
    testMergeSort(b,0,8,9); // 08 seconds


    //scanf("%d",&o);
    return 0;
}
