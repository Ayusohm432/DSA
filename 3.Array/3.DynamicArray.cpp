#include <iostream>
#include<stdio.h>


using namespace std;

int main() {

    //In c++       
    int* ptr;
    ptr = new int[10];
    delete []ptr;


    //In c
    int* p;
    p = (int*)malloc(10*sizeof(int));//dynamic allocation
    //Accessing
    p[0] = 10;
    free(p);//deleting allocated memmory space






    return 0;
}