#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

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

int get(struct Array arr , int index){
    if(index >=0 && index<arr.length){
        return arr.A[index];
    }
    return -1;
}

void set(struct Array* arr , int index , int x){
    if(index >=0 && index < arr->length){
        arr->A[index] = x;
    }
}

int Max(struct Array arr){
    int max = arr.A[0];
    int i;
    for(i=1 ; i<arr.length ; i++){
        if(arr.A[i] > max){
            max = arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr){
    int min = arr.A[0];
    int i;
    for(i=1 ; i<arr.length ; i++){
        if(arr.A[i] < min){
            min = arr.A[i];
        }
    }
    return min;
}

int Sum_Iterartive(struct Array arr){
    int sum = 0;
    int i;
    for(i=0 ; i<arr.length ; i++){
        sum += arr.A[i];
    }
    return sum;
}

int Sum_Recursive(struct Array arr , int n){
    if(n<0){
        return 0;
    }
    return Sum_Recursive(arr,n-1)+arr.A[n];
}

float average(struct Array arr){
    return (float)Sum_Iterartive(arr)/arr.length;
}

void reverse(struct Array* arr){
    int i=0;
    int j= arr->length-1;
    while(i<j){
        swap(&arr->A[i] , & arr->A[j]);
        i++;
        j--;
    }
    /*
    int i;
    for(i=0 ; i<arr.length/2 ; i++){
        swap(&arr[i] , &arr[arr.length-i-1]);
    }
    */
}

void Reverse(struct Array* arr){
    int n = arr->length;
    int* temp;
    temp = (int*)malloc(n*sizeof(int));

    for(int i=0 , j=n-1 ; i<n , j>=0 ; i++ , j--){
        temp[i] = arr->A[j];
    } 

    for(int i=0 ; i<n ; i++){
        arr->A[i] = temp[i];
    }
}

void reverse_range(struct Array* arr , int start , int end){
    while(start<end){
        swap(&arr->A[start] , &arr->A[end]);
        start++;
        end--;
    }
}

void left_Shift(struct Array* arr , int count){
    int n = arr->length;
    int i;
    for(i=0 ; i<n-count ; i++){
        arr->A[i] = arr->A[count+i];
    }
    for(int i=n-count ; i<n; i++){
        arr->A[i] = 0;
    }
}

void right_Shift(struct Array* arr , int count){
    int n = arr->length-1;

    for(int i=n ; i>=count ; i--){
        arr->A[i] = arr->A[i-count];
    }
    for(int i=0 ; i<count ; i++){
        arr->A[i] = 0;
    }
}

void rotate_left(struct Array* arr , int count){
    int n = arr->length;
    
    count %= n;

    reverse_range(arr,0,n-1);

    reverse_range(arr,n-count,n-1);

    reverse_range(arr,0,n-count-1);

}

void rotate_right(struct Array* arr , int count){
    int n =  arr->length;
    
    reverse_range(arr,0,n-1);

    reverse_range(arr,0,count-1);

    reverse_range(arr,count,n-1);    
}

void insertion_sorted_array(struct Array* arr , int val){
    int i = arr->length-1;
    if(arr->length == arr->size){
        return;
    }

    while(i>=0 && arr->A[i] > val){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = val;
    arr->length++;
}

bool is_sorted(struct Array arr){
    int i;
    for(i=0 ; i<arr.length-1 ; i++){
        if(arr.A[i] > arr.A[i+1]){
            return false;
        }
    }
    return true;
}

void rearrange(struct Array* arr){
    int i,j;
    i = 0;
    j = arr->length-1;
    
    while(i<j){
        while(i<arr->length && arr->A[i] < 0){
            i++;
        }
        while(j >= 0 && arr->A[j] >= 0){
            j--;
        }
        if(i<j){
            swap(&arr->A[i] , &arr->A[j]);
        }
    }
}

struct Array merge(struct Array arr1 , struct Array arr2){
    struct Array arr3;
    arr3.length = arr1.length + arr2.length;
    arr3.size = arr1.size + arr2.size;

    int k=0;
    for(int i=0 ; i<arr1.length ; i++){
        arr3.A[k++] = arr1.A[i];
    }
    for(int i=0 ; i<arr2.length ; i++){
        arr3.A[k++] = arr2.A[i];
    }

    return arr3;
}

struct Array merge_sorted(struct Array arr1 , struct Array arr2){
    struct Array arr3;
    arr3.length = arr1.length + arr2.length;
    arr3.size = arr1.size + arr2.size;

    int i,j,k;
    i=j=k=0;

    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            arr3.A[k++] = arr1.A[i++];
        }
        else{
            arr3.A[k++] = arr2.A[j++];
        }
    }
    for(; i<arr1.length ; i++){
        arr3.A[k++] = arr1.A[i];
    }
    for(; j<arr2.length ; j++){
        arr3.A[k++] = arr2.A[j];
    }
    return arr3;
}

struct Array Union(struct Array arr1 , struct Array arr2){
    struct Array arr3;
    arr3.length = 0;
    arr3.size = arr1.size + arr2.size;

    
    int i=0;
    int j=0;
    int k=0;

    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            arr3.A[k++] = arr1.A[i++];
        }
        else if(arr2.A[j] < arr1.A[i]){
            arr3.A[k++] = arr2.A[j++];
        }
        else{
            arr3.A[k++] = arr1.A[i++];
            j++;
        }
        arr3.length++;
    }
    while(j < arr2.length){
        arr3.A[k++] = arr2.A[j++];
        arr3.length++;
    }
    return arr3;
}

struct Array Intersection(struct Array arr1 , struct Array arr2){
    struct Array arr3;
    arr3.length = 0;
    arr3.size = arr1.size + arr2.size;

    int k = 0;

    for(int i=0 ; i<arr1.length ; i++){
        for(int j=0 ; j<arr2.length ; j++){
            if(arr1.A[i] == arr2.A[j]){
                arr3.A[k++] = arr1.A[i];
                arr3.length++;
                break;
            }
        }
    }
    return arr3;
}

struct Array Difference(struct Array arr1 , struct Array arr2){
    struct Array arr3;
    arr3.length = 0;
    arr3.size = arr1.size + arr2.size;

    int k = 0;
    bool flag;

    for(int i=0 ; i<arr1.length ; i++){
        flag = false;
        for(int j=0 ; j<arr2.length ; j++){
            if(arr1.A[i] == arr2.A[j]){
                flag = true;
                break;
            }
        }
        if(!flag){
            arr3.A[k++] = arr1.A[i];
            arr3.length++;
        }
    }
    return arr3;
}
int main(){
    struct Array arr = {{10,20,30,40,50},20,5};// stores {A[i],size,length};
    Append(&arr,60);
    Insert(&arr,2,100);
    Display(arr);
    printf("\n%d",Delete(&arr,4));
    Display(arr);

    int key = 30;
    printf("\n%d",Linear_Search(arr,key));
    printf("\n%d", Linear_Search_Transposition(&arr,key));
    Display(arr);
    printf("\n%d", Linear_Search_MoveToFront(&arr,key));
    Display(arr);

    printf("\n\n\n");
    struct Array arr1 = {{10,20,30,40,50,60,70,80,90,100},20,10};
    printf(" %d\n",Binary_Search_Iterative(arr1,30));
    printf("%d\n",Binary_Search_Iterative(arr1,00));
    printf(" %d\n",Binary_Search_Recursive(arr1,0,arr1.length,40));
    printf("%d\n",Binary_Search_Recursive(arr1,0,arr1.length,35));

    printf("\n\n\n");
    Display(arr1);
    printf("\n%d",get(arr1,5));
    set(&arr1,4,45);
    Display(arr1);
    printf("\n%d",Max(arr1));
    printf("\n%d",Min(arr1));
    printf("\n%d",Sum_Iterartive(arr1));
    printf("\n%d",Sum_Recursive(arr1,arr1.length-1));
    printf("\n%f",average(arr1));



    printf("\n\n\n");
    struct Array arr2 = {{1,2,3,4,5,6,7,8,9},10,9};
    Display(arr2);
    reverse(&arr2);
    Display(arr2);

    printf("\n\n\n");
    struct Array arr3 = {{1,2,3,4,5,6,7,8,9},10,9};
    Display(arr3);
    Reverse(&arr3);
    Display(arr3);

    
    printf("\n\n\n");
    struct Array arr30 = {{1,2,3,4,5,6,7,8,9},10,9};
    Display(arr30);
    reverse_range(&arr30,0,5);
    Display(arr30);
    
    

    printf("\n\n\n");
    struct Array arr4 = {{1,2,3,4,5,6,7,8,9},10,9};
    Display(arr4);
    left_Shift(&arr4,5);
    Display(arr4);

    printf("\n\n\n");
    struct Array arr5 = {{1,2,3,4,5,6,7,8,9},10,9};
    Display(arr5);
    right_Shift(&arr5,5);
    Display(arr5);

    printf("\n\n\n");
    struct Array arr6 = {{1,2,3,4,5,6,7,8,9},10,9};
    Display(arr6);
    rotate_left(&arr6,3);
    Display(arr6);

    printf("\n\n\n");
    struct Array arr7 = {{1,2,3,4,5,6,7,8,9},10,9};
    Display(arr7);
    rotate_right(&arr7,4);
    Display(arr7);

    printf("\n\n\n");
    struct Array arr8 = {{10,20,30,40,50,60,70,80,90},10,9};
    Display(arr8);
    insertion_sorted_array(&arr8,55);
    insertion_sorted_array(&arr8,13);
    Display(arr8);

    printf("\n%d",is_sorted(arr8));

    struct Array arr9 = {{2,-4,3,-2,-5,7,-3,-7,6,5,10,8},20,12};
    Display(arr9);
    rearrange(&arr9);
    Display(arr9);
    
    printf("\n\n\n");
    struct Array arr10 = {{3,6,23,54,63,2},10,6};
    struct Array arr11 = {{1,45,75,9,5,10,65},10,7};
    struct Array arr12 = merge(arr10 , arr11);
    Display(arr10);
    Display(arr11);
    Display(arr12);

    printf("\n\n\n");
    struct Array arr13 = {{1,2,3,6,8,10,20},10,7};
    struct Array arr14 = {{2,5,10,16,20,28,30,35,40,45},10,10};
    struct Array arr15 = merge_sorted(arr13,arr14);
    Display(arr13);
    Display(arr14);
    Display(arr15);

    printf("\n\n\n");
    Display(arr13);
    Display(arr14);
    struct Array arr16 = Union(arr13,arr14);
    Display(arr16); 

    printf("\n\n\n");
    Display(arr13);
    Display(arr14);
    struct Array arr17 = Intersection(arr13,arr14);
    Display(arr17);   

    printf("\n\n\n");
    Display(arr13);
    Display(arr14);
    struct Array arr18 = Difference(arr13,arr14);
    struct Array arr19 = Difference(arr14,arr13);
    Display(arr18);
    Display(arr19);

    return 0;
}