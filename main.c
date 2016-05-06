#include "main_includes.h"


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
    //testMergeSort(b,0,8,9); // 08 seconds

    testBinaryTreePrinting(a,9);


    //scanf("%d",&o);
    return 0;
}
