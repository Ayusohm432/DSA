#include<stdio.h>
#include<stdlib.h>

int main(){
    
    
    int A[3][4];
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<4 ; j++){
            A[i][j] = 2*i+j;
        }
    }

    int* B[3];
    B[0] = (int*)malloc(4*sizeof(int));
    B[1] = (int*)malloc(4*sizeof(int));
    B[2] = (int*)malloc(4*sizeof(int));
    B[2][1] = 10;

    int** C;
    C = (int**)malloc(3*sizeof(int*));
    C[0] = (int*)malloc(4*sizeof(int));
    C[1] = (int*)malloc(4*sizeof(int));
    C[2] = (int*)malloc(4*sizeof(int));
    C[2][1] = 10;

    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<4 ; j++){
            printf("%d  ",A[i][j]);
        }
    }
    printf("\n");

    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<4 ; j++){
            printf("%d  ",B[i][j]);
        }
    }
    printf("\n");


    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<4 ; j++){
            printf("%d  ",C[i][j]);
        }
    }
    printf("\n");

    //Accessing 2-D array elements
    printf("%d \n",A[1][2]);
    printf("%d \n",*(*(A+1)+2));
    
    


    for(int i=0 ; i<3 ; i++){
        free(B[i]);
    }

    for(int i=0 ; i<3 ; i++){
        free(C[i]);
    }
    free(C);


    return 0;
}