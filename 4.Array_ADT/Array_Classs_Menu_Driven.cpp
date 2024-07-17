#include <iostream>
using namespace std;


class Array{
    private:
        int *A;
        int size;
        int length;
        void Swap(int* x , int* y);
    public:
        Array(){
            size = 100;
            A = new int[100];
            length = 0;
        }
        Array(int size){
            this->size = size;
            length = 0;
            A = new int[size];  
        }
        void Display();
        void Append(int x);
        void Insert(int index , int x);
        int Delete(int index);
        int Linear_Search(int key);
        int Linear_Search_Transposition(int key);
        int Linear_Search_MoveToFront(int key);
        int Binary_Search_Iterative(int key);
        int Binary_Search_Recursive(int low , int high , int key);
        int Get(int index);
        void Set(int index , int x);
        int Max();
        int Min();
        int Sum_Iterartive();
        int Sum_Recursive(int n);
        float Average();
        void Reverse1();
        void Reverse();
        void Reverse_range(int start , int end);
        void Left_Shift(int count);
        void right_Shift(int count);
        void Rotate_left(int count);
        void Rotate_right(int count);
        void Insertion_sorted_array(int val);
        bool is_sorted();
        void rearrange();
        Array Merge(Array arr2);
        Array Merge_sorted(Array arr2);
        Array Union(Array arr2);
        Array Intersection(Array arr2);
        Array Difference(Array arr2);
        ~Array(){
            delete []A;
        }
};

void Array :: Swap(int* x , int* y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Array :: Display(){
    int i;
    printf("\nElements Are :- ");
    for(i=0 ; i<length ; i++){
        printf("%d ",A[i]);
    }
}

void Array :: Append(int x){
    if(length < size){
        A[length++] = x;
    }
}

void Array :: Insert(int index , int x){
    if(index >= 0 && index <= length){
        for(int i=length ; i>index ; i--){
             A[i] = A[i-1];
        }
        A[index] = x;
        length++;
    }
}

int Array :: Delete(int index){
    int x = 0;
    int i;
    if(index >= 0 && index <= length){
        x = A[index];
        for(i=index ; i<length-1 ; i++){
            A[i] = A[i+1];
        }
        length--;
        return x;
    }
    return -1;
}

int Array :: Linear_Search(int key){
    int i;
    for(i=0 ; i<length ; i++){
        if(key == A[i]){
            return i;
        }
    }
    return -1;
}

int Array :: Linear_Search_Transposition(int key){
    int i;
    for(i=0 ; i<length ; i++){
        if(key == A[i]){
            Swap(&A[i] , &A[i-1]);
            return i;
        }
    }
    return -1;
}

int Array :: Linear_Search_MoveToFront(int key){
    int i;
    for(i=0 ; i<length ; i++){
        if(key == A[i]){
            Swap(&A[i] , &A[0]);
            return i;
        }
    }
    return -1;
}

int Array :: Binary_Search_Iterative(int key){
    int low,mid,high;
    low = 0;
    high = length;

    while(low<=high){
        mid = (high+low)/2;
        if(key == A[mid]){
            return mid;
        }
        else if(key < A[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

int Array :: Binary_Search_Recursive(int low , int high , int key){
    int mid;
    if(low <= high){
        mid = (low+high)/2;
        if(key == A[mid]){
            return mid;
        }
        else if(key < A[mid]){
            return Binary_Search_Recursive(low,mid-1,key);
        }
        else{
            return Binary_Search_Recursive(mid+1,high,key);
        }
    }
    return -1;
}

int Array :: Get(int index){
    if(index >=0 && index<length){
        return A[index];
    }
    return -1;
}

void Array :: Set(int index , int x){
    if(index >=0 && index < length){
        A[index] = x;
    }
}

int Array :: Max(){
    int max = A[0];
    int i;
    for(i=1 ; i<length ; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

int Array :: Min(){
    int min = A[0];
    int i;
    for(i=1 ; i<length ; i++){
        if(A[i] < min){
            min = A[i];
        }
    }
    return min;
}

int Array :: Sum_Iterartive(){
    int sum = 0;
    int i;
    for(i=0 ; i<length ; i++){
        sum += A[i];
    }
    return sum;
}

int Array :: Sum_Recursive(int n){
    if(n<0){
        return 0;
    }
    return Sum_Recursive(n-1)+A[n];
}

float Array :: Average(){
    return (float)Sum_Iterartive()/length;
}

void Array :: Reverse1(){
    int i=0;
    int j= length-1;
    while(i<j){
        Swap(&A[i] , & A[j]);
        i++;
        j--;
    }
    /*
    int i;
    for(i=0 ; i<length/2 ; i++){
        Swap(&arr[i] , &arr[length-i-1]);
    }
    */
}

void Array :: Reverse(){
    int n = length;
    int* temp;
    temp = new int[n];

    for(int i=0 , j=n-1 ; i<n , j>=0 ; i++ , j--){
        temp[i] = A[j];
    } 

    for(int i=0 ; i<n ; i++){
        A[i] = temp[i];
    }
}

void Array :: Reverse_range(int start , int end){
    while(start<end){
        Swap(&A[start] , &A[end]);
        start++;
        end--;
    }
}

void Array :: Left_Shift(int count){
    int n = length;
    int i;
    for(i=0 ; i<n-count ; i++){
        A[i] = A[count+i];
    }
    for(int i=n-count ; i<n; i++){
        A[i] = 0;
    }
}

void Array :: right_Shift(int count){
    int n = length-1;

    for(int i=n ; i>=count ; i--){
        A[i] = A[i-count];
    }
    for(int i=0 ; i<count ; i++){
        A[i] = 0;
    }
}

void Array :: Rotate_left(int count){
    int n = length;
    
    count %= n;

    Reverse_range(0,n-1);

    Reverse_range(n-count,n-1);

    Reverse_range(0,n-count-1);

}

void Array ::  Rotate_right(int count){
    int n =  length;
    
    Reverse_range(0,n-1);

    Reverse_range(0,count-1);

    Reverse_range(count,n-1);    
}

void Array :: Insertion_sorted_array(int val){
    int i = length-1;
    if(length == size){
        return;
    }

    while(i>=0 && A[i] > val){
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = val;
    length++;
}

bool Array :: is_sorted(){
    int i;
    for(i=0 ; i<length-1 ; i++){
        if(A[i] > A[i+1]){
            return false;
        }
    }
    return true;
}

void Array :: rearrange(){
    int i,j;
    i = 0;
    j = length-1;
    
    while(i<j){
        while(i<length && A[i] < 0){
            i++;
        }
        while(j >= 0 && A[j] >= 0){
            j--;
        }
        if(i<j){
            Swap(&A[i] , &A[j]);
        }
    }
}

Array Array :: Merge(Array arr2){
    Array arr3;
    arr3.length = length + arr2.length;
    arr3.size = size + arr2.size;

    int k=0;
    for(int i=0 ; i<length ; i++){
        arr3.A[k++] = A[i];
    }
    for(int i=0 ; i<arr2.length ; i++){
        arr3.A[k++] = arr2.A[i];
    }

    return arr3;
}

Array Array :: Merge_sorted(Array arr2){
    Array arr3;
    arr3.length = length + arr2.length;
    arr3.size = size + arr2.size;

    int i,j,k;
    i=j=k=0;

    while(i<length && j<arr2.length){
        if(A[i] < arr2.A[j]){
            arr3.A[k++] = A[i++];
        }
        else{
            arr3.A[k++] = arr2.A[j++];
        }
    }
    for(; i<length ; i++){
        arr3.A[k++] = A[i];
    }
    for(; j<arr2.length ; j++){
        arr3.A[k++] = arr2.A[j];
    }
    return arr3;
}

Array Array :: Union(Array arr2){
    Array arr3;
    arr3.length = 0;
    arr3.size = size + arr2.size;

    
    int i=0;
    int j=0;
    int k=0;

    while(i<length && j<arr2.length){
        if(A[i] < arr2.A[j]){
            arr3.A[k++] = A[i++];
        }
        else if(arr2.A[j] < A[i]){
            arr3.A[k++] = arr2.A[j++];
        }
        else{
            arr3.A[k++] = A[i++];
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

Array Array :: Intersection(Array arr2){
    Array arr3;
    arr3.length = 0;
    arr3.size = size + arr2.size;

    int k = 0;

    for(int i=0 ; i<length ; i++){
        for(int j=0 ; j<arr2.length ; j++){
            if(A[i] == arr2.A[j]){
                arr3.A[k++] = A[i];
                arr3.length++;
                break;
            }
        }
    }
    return arr3;
}

Array Array :: Difference(Array arr2){
    Array arr3;
    arr3.length = 0;
    arr3.size = size + arr2.size;

    int k = 0;
    bool flag;

    for(int i=0 ; i<length ; i++){
        flag = false;
        for(int j=0 ; j<arr2.length ; j++){
            if(A[i] == arr2.A[j]){
                flag = true;
                break;
            }
        }
        if(!flag){
            arr3.A[k++] = A[i];
            arr3.length++;
        }
    }
    return arr3;
}

int main() {
    
    Array *arr1;
    int ch,size; 
    int element;
    int index;

    printf("Enter Size of Array : ");
    scanf("%d",&size);
    arr1 = new Array(size);

    do{
        printf("\n\n\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Dispaly\n");
        printf("6. Exit");

        printf("\n\n\nEnter Your Choice :- ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("\nEnter an Element : ");
                scanf("%d",&element);
                printf("\nEnter Index : ");
                scanf("%d",&index);
                arr1->Insert(index , element);
                break;

            case 2:
                printf("Enter Index for Element to be deleted : ");
                scanf("%d",&index);
                element = arr1->Delete(index);
                printf("Deleted Element is %d\n",element);
                break;

            case 3: 
                printf("Emter an element to search : ");
                scanf("%d",&element);
                index = arr1->Linear_Search(element);
                printf("Element i=s Found at Index %d ",index);
                break;
                
            case 4:
                printf("Sum is : %d\n",arr1->Sum_Iterartive());
                break;
            
            case 5:
                arr1->Display();
                break;

        }
    }while(ch<6);

    return 0;
}