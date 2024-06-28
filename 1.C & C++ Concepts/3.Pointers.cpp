#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
struct Rectangle{
    int length;
    int breadth;
};
int main() {
    int a = 10;
    int* p;
    p = &a;
    cout<<a<<endl<<*p<<endl;
    cout<<&a<<endl<<p<<endl;


    int A[10] = {10,20,30,40,50,60,70,80,90,100};
    int *ptr;
    ptr = A;
    for(int i=0 ; i<10 ; i++){
        cout<<ptr[i]<<" "<<*ptr<<endl;
    }

    int *q =  (int*)malloc(10*sizeof(int));
    //int *q = new int[10];
    for(int i=0 ; i<10 ; i++){
        q[i] = i+1;
    }
    for(int i=0 ; i<10 ; i++){
        cout<<q[i]<<endl;
    }
    free(q);
    //delete[] q;
    


    //Size of pointer variable is independent of datatype.

    int *p1;
    float *p2;
    char *p3;
    double *p4;
    struct Rectangle *p5;

    cout<<sizeof(p1)<<endl;
    cout<<sizeof(p2)<<endl;
    cout<<sizeof(p3)<<endl;
    cout<<sizeof(p4)<<endl;
    cout<<sizeof(p5)<<endl;


    return 0;
}