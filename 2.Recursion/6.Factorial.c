#include<stdio.h>


int recursiveFactorial(int n){
    if(n==0 || n==1){
        return 1;
    }
    else{
        return recursiveFactorial(n-1)*n;
    }
}


int iterativeFactorial(int n){
    int fact = 1;
    for(int i=1 ; i<=n ; i++){
        fact *= i;
    }
    return fact; 
}

int main(){
    int num = 10;
    printf("\nFactorial of %d using Recursion = %d",num,recursiveFactorial(num));
    printf("\nFactorial of %d using Loop      = %d",num,iterativeFactorial(num));

    return 0;
}