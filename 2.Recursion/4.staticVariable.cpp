#include <iostream>
using namespace std;

//using local Variable
/*
local variable is changed everytime when the recursion happens since it is created in stack memory
*/
int fun1(int n){
    if(n>0){
        return fun1(n-1)+n;
    }
    return 0;
}

//Using Static Variable(instead gloabal variable)
/*
Only on copy of static variable or global variable will be craeted in code section of memory so that and during recursion return in function same value will be added everytime 
*/
int fun2(int n){
    static int x = 0;
    if(n>0){
        x++;
        return fun2(n-1)+x;
    }
    return 0;
}


int main() {
            
    int usingLocal;
    usingLocal = fun1(5);
    cout<<usingLocal<<endl;

    int usingstatic = fun2(5);
    cout<<usingstatic<<endl;



    return 0;
}