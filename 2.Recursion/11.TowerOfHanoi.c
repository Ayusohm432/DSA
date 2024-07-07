#include<stdio.h>

void TOH(int n , int A , int B , int C){
    if(n>0){
        TOH(n-1 , A , C , B);
        printf("Move disk %d from %d to %d\n",n,A,C);
        TOH(n-1 , B , A ,C);
    }
}

int main(){

    TOH(3,1,2,3);
    printf("\n\n");

    return 0;
}
