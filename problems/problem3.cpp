/*
    Find the output of
    int main()
    {
        int x=3,y=4,z=4;
        printf("ans=%d\n",(z>=y>=x?100:200));
        return 0;
    }

    NOTE:
        Was asked in Zoho campus drive.
*/
#include <iostream>


int problem3_main()
{
    using namespace std;
    int x=3,y=4,z=4;
    printf("ans=%d\n",(z>=y>=x?100:200)); // answer 200.
    return 0;
}

