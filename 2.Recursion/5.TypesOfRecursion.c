/*
1.Tail Recursion
2.Head Recursion
3.Tree Recursion
4.Direct Recursion
5.Indirect Recursion
*/

//1. Tail Recursion
/*  
    # if recursive call is the last statement in the Recursion Function.
    # The function is not performing any statement/operation during returning Time
    # Loop is more efficient than Tail recursion

*/

//2.Head Recursion
/*
    # If recursive call is the first statement in the Recursion Function.
    # The function is performing some statement/operation during returning Time
    # The function should not perform any operation before the function call.

*/

//3.Linesr Recursion
/*
    # If a Recursive function is calling itself only 1 time.

*/

//4.Tree Recursion
/*
    # If a Reursive function is calling itself more than 1 time .

*/

//5.Indirect Recursion
/*
    # Ther are more than one Function and they are calling one another in a circular fashion.
*/


//6.Nested Recursion
/*
    # Recursive function call will pass recursive function as its argument
*/


#include<stdio.h>
#include<conio.h>

void tailRecursion(int n){
    if(n>0){
        printf("%d  ",n);
        tailRecursion(n-1);
    }
}


void headRecusrion(int n){
    if(n>0){
        headRecusrion(n-1);
        printf("%d  ", n);
    }
}


void linearRecursion(int n){
    if(n>0){
        printf("%d  ",n);
        linearRecursion(n-1);
        printf("%d  ",n);
    }
}


void treeRecursion(int n){
    if(n>0){
        printf("%d  ",n);
        treeRecursion(n-1);
        treeRecursion(n-1);
    }
}

void indirectRecursion2(int n);
void indirectRecursion1(int n){
    if(n>0){
        printf("%d  " , n);
        indirectRecursion2(n-1);
    }
}

void indirectRecursion2(int n){
    if(n>1){
        printf("%d  ",n);
        indirectRecursion1(n/2);
    }
}

int nestedRecursion(int n){
    if(n>100){
        return n-10;
    }
    else{
        return nestedRecursion(nestedRecursion(n+11));
    }
}

int main(){
    printf("Tail Recursion :- ");
    tailRecursion(20);

    printf("\nHead Recursion :- ");
    headRecusrion(20);

    printf("\nLinear Recursion :- ");
    linearRecursion(20);

    printf("\nTree Recursion :- ");
    treeRecursion(5);

    printf("\nIndirect Recursion :- ");
    indirectRecursion1(20);

    int r = nestedRecursion(95);
    printf("\nNested Recursion :-  %d" , r);

    return 0;
}



