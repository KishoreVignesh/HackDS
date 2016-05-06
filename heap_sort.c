#include <unistd.h>



struct binary_tree_node{
 int value;
 struct binary_tree_node *left_child;
 struct binary_tree_node *right_child;
 struct binary_tree_node *parent;
};

//struct binary_tree_node * last_binary_tree_node;

struct binary_tree_node* build_binary_tree_from_array(int a[],struct binary_tree_node *currentNode,int i,int size)
{

    if (currentNode == 0)
    {
        currentNode=malloc(sizeof(struct binary_tree_node));
        currentNode->left_child = 0;
        currentNode->right_child = 0;
        currentNode->parent = 0;
    }
    currentNode->value = a[i];

    if (((2*i)+1)<size)
    {
        struct binary_tree_node *tmpNode = malloc(sizeof(struct binary_tree_node));
        tmpNode->value = 0;
        tmpNode->left_child = 0;
        tmpNode->right_child = 0;
        //setting it as the left child
        tmpNode->parent = currentNode;
        currentNode->left_child = tmpNode;
        build_binary_tree_from_array(a,tmpNode,((2*i)+1),size);
    }

    if (((2*i)+2)<size)
    {
        struct binary_tree_node *tmpNode = malloc(sizeof(struct binary_tree_node));
        tmpNode->value = 0;
        tmpNode->left_child = 0;
        tmpNode->right_child = 0;
        //setting it as the left child
        currentNode->right_child = tmpNode;
        tmpNode->parent=currentNode;
        build_binary_tree_from_array(a,tmpNode,((2*i)+2),size);
    }

    return currentNode;
}

void print_binary_tree_internal(struct binary_tree_node* root,int level)
{
    int i=0;
    if (root !=0)
    {
        print_binary_tree_internal(root->right_child,level+1);
        for(i=0;i<level;i++)
            printf("\t");
        printf("[%d]\n", root->value);

        print_binary_tree_internal(root->left_child,level+1);


    }
}

// Tree Traversal in Middle Left Right
struct binary_tree_node* lastNodeMLR(struct binary_tree_node *root)
{
    if (root !=0)
    {
        //The following variable is in the global scope.
//        last_binary_tree_node = root;
//        lastNodeMLR(root->left_child);
//        lastNodeMLR(root->right_child);

        if (root->right_child !=0 )
            return lastNodeMLR(root->right_child);
        else if (root->left_child !=0 )
            return lastNodeMLR(root->left_child);
        else
            return root;

    }
}



void print_binary_tree(struct binary_tree_node * root){
    printf("\n");
    print_binary_tree_internal(root,0);
    printf("\n");
    printf("-----------------------------------------\n");
    sleep(5);
}

void checkHeapOrderChange(struct binary_tree_node *root)
{
    int tmp=0;
    struct binary_tree_node *swap=root;
    if (root->left_child !=0 && root->left_child->value > swap->value)
        swap = root->left_child;
    if (root->right_child !=0 && root->right_child->value > swap->value)
        swap = root->right_child;
    if (root != swap)
    {
        tmp = root->value;
        root->value=swap->value;
        swap->value=tmp;
        // repeat shifting down the child.
        checkHeapOrder(root);
    }
}

void checkHeapOrder(struct binary_tree_node * node)
{
    if (node != 0)
    {
        checkHeapOrder(node->left_child);
        checkHeapOrder(node->right_child);
        checkHeapOrderChange(node);
    }
}


void heapSortInternal(int a[],struct binary_tree_node *root,int size)
{
    int i=size-1;
    while (root != 0)
    {
        struct binary_tree_node *lastNode = lastNodeMLR(root);
        a[i--]= root->value;
        if (root == lastNode)
        {
            free(root);
            root=0;
        }
        else
        {
            root->value = lastNode->value;
            if (lastNode == lastNode->parent->left_child)
                lastNode->parent->left_child=0;
            else
                lastNode->parent->right_child=0;
            free(lastNode);
            checkHeapOrder(root);
            print_binary_tree(root);
        }
    }
}

void heapSort(int a[],int size)
{
    struct binary_tree_node *root = build_binary_tree_from_array(a,0,0,size);
    print_binary_tree(root);
    checkHeapOrder(root);
    heapSortInternal(a,root,size);
}

