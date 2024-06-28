#include <iostream>
using namespace std;
// void fun(int A[], int n){
//     for(int i=0 ; i<n ; i++){
//         cout<<A[i]<<" ";
//     }
//     cout<<endl;
// }

void fun(int *A, int n){
    for(int i=0 ; i<n ; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
int main() {
    int A[] = {10,20,30,40};
    int n = 4;
    fun(A,n);
    for(int x : A){
        cout<<x<<endl;
    }        
            
    return 0;
}