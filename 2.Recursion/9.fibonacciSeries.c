#include<stdio.h>
#include<stdlib.h>

int n;
int* fib;
int iterativeFib(int n){
    int t0 = 0 , t1 = 1 , s = 0 , i;
    if(n<=1){
        return n;
    }

    for(i=2 ; i<=n ; i++){
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }

    return s;

}

int recursiveFib(int n){
    if(n<=1){
        return n;
    }
    else{
        return recursiveFib(n-1)+recursiveFib(n-2);
    }
}

int memorisationFib(int n){
    if(n<=1){
        fib[n] = n;
        return n;
    }
    else{
        if(fib[n-2] == -1){
            fib[n-2] = memorisationFib(n-2);
        }
        if(fib[n-1] == -1){
            fib[n-1] = memorisationFib(n-1);
        }
        return fib[n] = fib[n-2]+fib[n-1];
    }
}


int main(){
    printf("Enter N : ");
    scanf("%d",&n);

    fib = (int*) malloc((n+1)* sizeof(int)) ;
    for(int i=0 ; i<=n ; i++){
        fib[i] = -1;
    }
 
    printf("Fib using Loop =         %d\n",iterativeFib(n));
    printf("Fib using Recursion =    %d\n",recursiveFib(n));
    printf("Fib using Memorisation = %d\n",memorisationFib(n));

    //For printing Fibonacci Series
    for(int i=0 ; i<=n ; i++){
        printf("%d ",fib[i]);
    }
    return 0;
}
