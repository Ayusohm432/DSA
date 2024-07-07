#include<stdio.h>

int recursiveSum(int n){
    if(n == 0){
        return 0;
    }
    else{
        return recursiveSum(n-1)+n;
    }
}

int iterativeSum(int n){
    int sum = 0;
    for(int i=1 ; i<=n ; i++){
        sum += i;
    }
    return sum;
}

int formulaSum(int n){
    return (n*(n+1))/2;
}


int main(){
    int num = 20;

    printf("\nSum Using Recursion = %d" , recursiveSum(num));
    printf("\nSum Using Loop      = %d" , iterativeSum(num));
    printf("\nSum Using Formula   = %d" , formulaSum(num));

    return 0;
}