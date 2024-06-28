// For n input there are n+1 call of the function,
// Space complexity = o(n);

#include <iostream>
using namespace std;
void increasing(int n){
    if(n>0){
        cout<<n<<" ";
        increasing(n-1);
    }
}

void reverse(int n){
    if(n>0){
        reverse(n-1);
        cout<<n<<" ";
    }
}
int main() {
    int num;
    cout<<"Enter A Number : ";
    cin>>num;
    increasing(num);
    cout<<endl;
    reverse(num);        
            
    return 0;
}