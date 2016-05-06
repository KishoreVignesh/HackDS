

//extern struct binary_tree_node *last_binary_tree_node;



void testBinaryTreePrinting(int a[],int size)
{

    printf("\nPassed Array is ");
    printArray(a,size);

//    struct binary_tree_node * root= build_binary_tree_from_array(a,0,0,size);
//    print_binary_tree(root);
//
//    printf("\n Satisfying the heap property (MAX Heap)  ");
//    checkHeapOrder(root);
//    print_binary_tree(root);
//
//    printf("\nTesting the last node value %d",lastNodeMLR(root)->value);
//
//    printf("\nTesting the array building method..");
//    heapSortInternal(a,root,size);
    heapSort(a,size);
    printf("\nResult after heap sort is");
    printArray(a,size);

}
