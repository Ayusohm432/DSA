#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

template<class T>
class Array{
    private:
        T *A;
        int size;
        int length;
        void Swap(T* x , T* y);
    public:
        Array(){
            size = 100;
            A = new T[100];
            length = 0;
        }
        Array(int size){
            this->size = size;
            length = 0;
            A = new T[size];  
        }
        void Display();
        void Append(T x);
        void Insert(int index , T x);
        T Delete(int index);
        int Linear_Search(T key);
        int Linear_Search_Transposition(T key);
        int Linear_Search_MoveToFront(T key);
        int Binary_Search_Iterative(T key);
        int Binary_Search_Recursive(int low , int high , T key);
        T Get(int index);
        void Set(int index , T x);
        T Max();
        T Min();
        T Sum_Iterartive();
        T Sum_Recursive(int n);
        float Average();
        void Reverse1();
        void Reverse();
        void Reverse_range(int start , int end);
        void Left_Shift(int count);
        void right_Shift(int count);
        void Rotate_left(int count);
        void Rotate_right(int count);
        void Insertion_sorted_Array(T val);
        bool is_sorted();
        void rearrange();
        Array<T> Merge(Array<T> arr2);
        Array<T> Merge_sorted(Array<T> arr2);
        Array<T> Union(Array<T> arr2);
        Array<T> Intersection(Array<T> arr2);
        Array<T> Difference(Array<T> arr2);
        ~Array(){
            delete []A;
        }
};

template<class T>
void Array<T> :: Swap(T* x , T* y){
    T temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

template<class T>
void Array<T> :: Display(){
    int i;
    printf("\nElements Are :- ");
    for(i=0 ; i<length ; i++){
        cout<<A[i]<<" ";
    }
}

template<class T>
void Array<T> :: Append(T x){
    if(length < size){
        A[length++] = x;
    }
}


template<class T>
void Array<T> :: Insert(int index , T x){
    if(index >= 0 && index <= length){
        for(int i=length ; i>index ; i--){
             A[i] = A[i-1];
        }
        A[index] = x;
        length++;
    }
}

template<class T>
T Array<T> :: Delete(int index){
    T x = 0;
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

template<class T>
int Array<T> :: Linear_Search(T key){
    int i;
    for(i=0 ; i<length ; i++){
        if(key == A[i]){
            return i;
        }
    }
    return -1;
}

template<class T>
int Array<T> :: Linear_Search_Transposition(T key){
    int i;
    for(i=0 ; i<length ; i++){
        if(key == A[i]){
            if(i > 0) {
                Swap(&A[i] , &A[i-1]);
            }
            return i;
        }
    }
    return -1;
}

template<class T>
int Array<T> :: Linear_Search_MoveToFront(T key){
    int i;
    for(i=0 ; i<length ; i++){
        if(key == A[i]){
            Swap(&A[i] , &A[0]);
            return i;
        }
    }
    return -1;
}
template<class T>
int Array<T> :: Binary_Search_Iterative(T key){
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

template<class T>
int Array<T> :: Binary_Search_Recursive(int low , int high , T key){
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

template<class T>
T Array<T> :: Get(int index){
    if(index >=0 && index<length){
        return A[index];
    }
    return -1;
}

template<class T>
void Array<T> :: Set(int index , T x){
    if(index >=0 && index < length){
        A[index] = x;
    }
}

template<class T>
T Array<T> :: Max(){
    int max = A[0];
    int i;
    for(i=1 ; i<length ; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

template<class T>
T Array<T> :: Min(){
    int min = A[0];
    int i;
    for(i=1 ; i<length ; i++){
        if(A[i] < min){
            min = A[i];
        }
    }
    return min;
}

template<class T>
T Array<T> :: Sum_Iterartive(){
    int sum = 0;
    int i;
    for(i=0 ; i<length ; i++){
        sum += A[i];
    }
    return sum;
}

template<class T>
T Array<T> :: Sum_Recursive(int n){
    if(n < 0){
        return 0;
    }
    return A[n] + Sum_Recursive(n-1);
}

template<class T>
float Array<T> :: Average(){
    return (float)Sum_Iterartive()/length;
}

template<class T>
void Array<T> :: Reverse1(){
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

template<class T>
void Array<T> :: Reverse(){
    int n = length;
    int* temp;
    temp = new T[n];

    for(int i=0 , j=n-1 ; i<n ; i++ , j--){
        temp[i] = A[j];
    } 

    for(int i=0 ; i<n ; i++){
        A[i] = temp[i];
    }
    delete []temp;
}


template<class T>
void Array<T> :: Reverse_range(int start , int end){
    while(start<end){
        Swap(&A[start] , &A[end]);
        start++;
        end--;
    }
}

template<class T>
void Array<T> :: Left_Shift(int count){
    int n = length;
    int i;
    for(i=0 ; i<n-count ; i++){
        A[i] = A[count+i];
    }
    for(int i=n-count ; i<n; i++){
        A[i] = 0;
    }
}

template<class T>
void Array<T> :: right_Shift(int count){
    int n = length-1;

    for(int i=n ; i>=count ; i--){
        A[i] = A[i-count];
    }
    for(int i=0 ; i<count ; i++){
        A[i] = 0;
    }
}

template<class T>
void Array<T> :: Rotate_left(int count){
    int n = length;
    
    count %= n;

    Reverse_range(0,n-1);

    Reverse_range(n-count,n-1);

    Reverse_range(0,n-count-1);

}

template<class T>
void Array<T> ::  Rotate_right(int count){
    int n =  length;
    
    Reverse_range(0,n-1);

    Reverse_range(0,count-1);

    Reverse_range(count,n-1);    
}

template<class T>
void Array<T> :: Insertion_sorted_Array(T val){
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

template<class T>
bool Array<T> :: is_sorted(){
    int i;
    for(i=0 ; i<length-1 ; i++){
        if(A[i] > A[i+1]){
            return false;
        }
    }
    return true;
}

template<class T>
void Array<T> :: rearrange(){
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

template<class T>
Array<T> Array<T> :: Merge(Array<T> arr2){
    Array<T> arr3;
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

template<class T>
Array<T> Array<T> :: Merge_sorted(Array<T> arr2){
    Array<T> arr3;
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

template<class T>
Array<T> Array<T> :: Union(Array<T> arr2){
    Array<T> arr3;
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

template<class T>
Array<T> Array<T> :: Intersection(Array<T> arr2){
    Array<T> arr3;
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

template<class T>
Array<T> Array<T> :: Difference(Array<T> arr2){
    Array<T> arr3;
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

    Array<int> arr(10);

    arr.Insert(0,5);
    arr.Insert(1,10);
    arr.Insert(2,27);
    arr.Insert(3,57);
    arr.Insert(4,65);
    arr.Insert(5,78);
    arr.Display();
    cout<<endl<<arr.Delete(0);
    arr.Display();

    cout<<endl<<endl;
    
    Array<float> arr1(10);
    arr1.Insert(0,5.3);
    arr1.Insert(1,10.5);
    arr1.Insert(2,27.6);
    arr1.Insert(3,5.7);
    arr1.Insert(4,6.5);
    arr1.Insert(5,7.8);
    arr1.Display();
    cout<<endl<<arr1.Delete(0)<<endl;
    arr1.Display(); 


    cout<<endl<<endl;

    
    Array<char> arr10(10);
    arr10.Insert(0,'A');
    arr10.Insert(1,'B');
    arr10.Insert(2,'C');
    arr10.Insert(3,'D');
    arr10.Insert(4,'E');
    arr10.Insert(5,'F');
    arr10.Display();
    cout<<endl<<arr10.Delete(0)<<endl;
    arr10.Display();

    cout<<endl<<endl;

    
    // Array<string> arr11(10);
    // arr11.Insert(0,"What");
    // arr11.Insert(1,"is");
    // arr11.Insert(2,"the");
    // arr11.Insert(3,"difference");
    // arr11.Insert(4,"Between");
    // arr11.Insert(5,"DSA");
    // arr11.Display();
    // cout<<endl<<arr11.Delete(5)<<endl;
    // arr11.Display();

    return 0;
}