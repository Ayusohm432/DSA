#include <iostream>
using namespace std;

int main() {
     int a =10;
     //Declaring Reference and Initializing
     int &r = a;

    cout<<"a = "<<a<<endl;
    r++;
    cout<<"r = "<<r<<endl;
    cout<<"a = "<<a<<endl;
    int b = 20;
    //Assignment
    r=b;
    cout<<"b = "<<b<<endl;
    cout<<"r = "<<r<<endl;
    cout<<"a = "<<a<<endl;
    
    return 0;
}