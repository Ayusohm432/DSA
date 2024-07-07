#include<stdio.h>
// n will give precise value
double recursiveTaylor(int x , int n){
    static double s;
    
    if(n == 0){
        return s;
    }

    s = 1 + x * s / n ;

    return recursiveTaylor(x,n-1);
}

double iterativeTaylor(int x , int n){
    double s = 1;

    for(;n>0;n--){
        s = 1 + x * s / n ;
    }

    return s;
}
int main(){
    printf("Using Recursion = %lf \n",recursiveTaylor(1,10));
    printf("Using Loop = %lf \n",iterativeTaylor(1,10));

    
    printf("Using Recursion = %lf \n",recursiveTaylor(2,10));
    printf("Using Loop = %lf \n",iterativeTaylor(2,10));

    return 0;
}