#include<stdio.h>


int power(int m , int n){
    if(n == 0){
        return 1;
    }
    else{
        return power(m,(n-1))*m;
    }
}


int power1(int m , int n){
    if(n==0){
        return 1;
    }
    if(n%2 == 0){
        return power1(m*m , n/2);
    }
    else{
        return m*power(m*m , (n-1)/2);
    }
}


int main(){
    printf("5 ^ 3 = %d\n" , power(5,3));
    printf("5 ^ 3 = %d\n" , power1(5,3));
    

    printf("9 ^ 8 = %d\n" , power1(9,8));
    printf("9 ^ 8 = %d\n" , power1(9,8));


}