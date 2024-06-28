#include <iostream>
using namespace std;

//Structure Definition;
struct Rectangle{
    int length;
    int breadth;
    char x;
};
/*  Structure Definition And Declaration

    struct Rectangle{
        int length;
        int breadth;
    } r1,r2,r3;


*/

//Structure Declaration
struct Rectangle r1;

int main() {
    //Structure Declaration and initialization
    struct Rectangle r2={20,10};

    // The structure will take the size og biggest variable for smaller variable also. here actual size is 12 but by definition it should be 9.
    printf("%lu\n",sizeof(r2));// formatter for long unsigned int.


    cout<<r2.length<<endl;
    cout<<r2.breadth<<endl;
    r2.breadth=27;
    r2.length=49;
    cout<<r2.length<<endl;
    cout<<r2.breadth<<endl;
            
    return 0;
}