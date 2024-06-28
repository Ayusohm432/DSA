#include <iostream>
using namespace std;

int main() {
    int A[5];
    A[0] = 12;
    A[1] = 25;
    A[2] = 30;
    cout<<sizeof(A);
    cout<<endl<<A[1]<<endl;
    printf("%d\n",A[3]);

    int B[5] = {10,20,30,40,50};
    int C[] ={10,23,43,54};
            
    return 0;
}