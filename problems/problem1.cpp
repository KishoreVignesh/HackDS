/*
    Given an Array ,its size and the target, we need to find
    number of ways by which we can sum up the contents inside the array
    to get the given target.

    Output -> Just the number of ways

    Its a combination problem we need to choose one element at a time in
    the array and then see if it sums up to the given target. I think
    reading the code will give better explanation. we are hackers.

    NOTE:
        This problem was asked in the CEI technical round.
*/
#include <iostream>
#include <unistd.h>

extern void printArray (int* ,int);

namespace problem1
{
using namespace std;
//we need to set this from the problem1_main
int target;
int counter=0;

int factorial(int a)
{
    if (a<=1)
    {
    return 1;
    }
    else
    {
        return (a*factorial(a-1));
    }
}

int last_poition_of_minus_one_in_array(int a[],int length)
{
    int tmp=-1;
    for (int j=0;j<length;j++)
    {
        if (a[j]==-1)
            tmp = j;
    }
    return tmp;
}

int number_of_minus_one_in_array(int a[],int length)
{
    int times=0;
    for (int j=0;j<length;j++)
    {
        if (a[j]==-1)
            times++;
    }
    return times;
}
void find_count_internal(int a[],int length,int sum,int number_of_choices)
{


    int tmp[length];
    int off_sum=sum;
    if (sum<target && number_of_minus_one_in_array(a,length)<number_of_choices)
    {
        // we need to select a number each time.
        // Its a computer we need to try each cases.
        // and for the position where we pick is replaced by -1
        for (int i=0;i<length;i++)
        {
            // At each iteration the sum must be back to its initial value.
            sum=off_sum;
            // Since arrays are passed by reference. we need to create a
            // copy.
            for (int k=0;k<length;k++)
                tmp[k]=a[k];
//        cout<<"copied tmp array is";
//        printArray(tmp,length);
        // we should not pick a number which is already picked up.
        while((tmp[i] == -1)&&(i<length))
            i++;
        // If we dont have any other element left.
        if (i==length)
            return;
        else
        {
            sum+=tmp[i];
            // we place -1 if we had already selected the item.
            tmp[i]=-1;
            // Then we need to pick the next number.
//            cout<<"While Operation array is";
//            printArray(tmp,length);
//            cout<<"sum is "<<sum<<endl;
//            sleep(3);
            find_count_internal(tmp,length,sum,number_of_choices);
        }
        }


    }
    else if (sum == target && number_of_minus_one_in_array(a,length)==number_of_choices)
    {

        counter++;
        cout<<"While Operation Matched when array is";
        printArray(a,length);
        cout<<"sum is "<<sum<<endl;
        sleep(5);
    }
    else{
        return;
    }

}


int find_count(int a[],int length)
{
    int combination_ways=0;

    for (int i=1;i<=length;i++)
    {
        counter=0;
        find_count_internal(a,length,0,i);
        counter= (counter/ factorial(i));
        combination_ways+=counter;
    }
    return combination_ways;
}
}













int problem1_main()
{
    using namespace std;
    using namespace problem1;

    int length=9;
    int a[] ={1,2,3,4,5,6,7,8,9};
    cout<<"Testing Problem1:"<<endl;
    cout<<"The Passed array is "<<endl;
    printArray(a,length);
    target = length;
    cout<<"The target set is "<<target<<endl;

    cout<<"Number of ways: "<< find_count(a,length)<<endl;

    return 0;
}
