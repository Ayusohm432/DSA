#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


void swap(int* x , int* y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

struct Array{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    printf("\nElements Are :- ");
    for(i=0 ; i<arr.length ; i++){
        printf("%d ",arr.A[i]);
    }
}

void Append(struct Array* arr , int x){
    if(arr->length < arr->size){
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array* arr , int index , int x){
    if(index >= 0 && index <= arr->length){
        for(int i=arr->length ; i>index ; i--){
             arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array* arr , int index){
    int x = 0;
    int i;
    if(index >= 0 && index<=arr->length){
        x = arr->A[index];
        for(i=index ; i<arr->length-1 ; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return -1;
}

int Linear_Search(struct Array arr , int key){
    int i;
    for(i=0 ; i<arr.length ; i++){
        if(key == arr.A[i]){
            return i;
        }
    }
    return -1;
}

int Linear_Search_Transposition(struct Array* arr , int key){
    int i;
    for(i=0 ; i<arr->length ; i++){
        if(key == arr->A[i]){
            swap(&arr->A[i] , &arr->A[i-1]);
            return i;
        }
    }
    return -1;
}

int Linear_Search_MoveToFront(struct Array* arr , int key){
    int i;
    for(i=0 ; i<arr->length ; i++){
        if(key == arr->A[i]){
            swap(&arr->A[i] , &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int Binary_Search_Iterative(struct Array arr , int key){
    int low,mid,high;
    low = 0;
    high = arr.length;

    while(low<=high){
        mid = (high+low)/2;
        if(key == arr.A[mid]){
            return mid;
        }
        else if(key < arr.A[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

int Binary_Search_Recursive(struct Array arr , int low , int high , int key){
    int mid;
    if(low <= high){
        mid = (low+high)/2;
        if(key == arr.A[mid]){
            return mid;
        }
        else if(key < arr.A[mid]){
            return Binary_Search_Recursive(arr,low,mid-1,key);
        }
        else{
            return Binary_Search_Recursive(arr,mid+1,high,key);
        }
    }
    return -1;
}

int main(){
    struct Array arr = {{10,20,30,40,50},20,5};// stores {A[i],size,length};
    Append(&arr,60);
    Insert(&arr,2,100);
    Display(arr);
    printf("\n%d",Delete(&arr,4));
    Display(arr);

    int key = 30;
    int pos = Linear_Search(arr,key);
    if(pos == -1){
        printf("\n%d is not present in the Array\n",key);
    }
    else{
        printf("\n%d is found at index %d \n",key,pos);   
    }


    int pos1 = Linear_Search_Transposition(&arr,key);
    if(pos1 == -1){
        printf("\n%d is not present in the Array\n",key);
    }
    else{
        printf("\n%d is found at index %d \n",key,pos1);   
    }
    Display(arr);


    int pos2 = Linear_Search_MoveToFront(&arr,key);
    if(pos2 == -1){
        printf("\n%d is not present in the Array\n",key);
    }
    else{
        printf("\n%d is found at index %d \n",key,pos2);   
    }
    Display(arr);

    printf("\n");
    struct Array arr1 = {{10,20,30,40,50,60,70,80,90,100},20,10};
    printf("%d\n",Binary_Search_Iterative(arr1,30));
    printf("%d\n",Binary_Search_Iterative(arr1,00));
    printf("%d\n",Binary_Search_Recursive(arr1,0,arr1.length,40));
    printf("%d\n",Binary_Search_Recursive(arr1,0,arr1.length,35));


    



    return 0;
}