#include <iostream>
using namespace std;
template<class T>
class Arithematic{
   T a;
   T b;
   public:
        Arithematic(T a , T b);
        T add();
        T sub();
};

template<class T>
Arithematic<T> :: Arithematic(T a , T b){
    this->a = a;
    this->b = b;
}

template<class T>
T Arithematic<T> :: add(){
    return a+b;
}

template<class T>
T Arithematic<T> :: sub(){
    return (a-b);
}
int main() {
    Arithematic<int> ar(10,5);
    cout<<ar.add()<<endl;
    cout<<ar.sub()<<endl;

    Arithematic<float> ar1(4.5f,6.4f);
    cout<<ar1.add();
    cout<<endl<<ar1.sub()<<endl;

    Arithematic<string> st("Ayush", " Kumar");
    cout<<st.add();        
    // cout<<st.sub()<<endl;        
    return 0;
}