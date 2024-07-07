#include<stdio.h>

int fact(int n){
    if(n == 0){
        return 1;
    }
    else{
        return fact(n-1)*n;
    }
}

int formulaCombination(int n , int r){
    int num = fact(n);
    int den = fact(r) * fact(n-r);

    return num/den;
}

int recursiveCombination(int n , int r){
    if(r == 0 || r==n ){
        return 1;
    }
    else{
        return recursiveCombination(n-1,r-1) + recursiveCombination(n-1,r);
    }
}

int main(){
    printf("Comination of 5c4 using formula =   %d\n",formulaCombination(5,3));
    printf("Comination of 5c4 using Recursion = %d\n",recursiveCombination(5,3));


    return 0;
}