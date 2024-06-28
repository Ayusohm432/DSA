#include <iostream>
using namespace std;
struct Rectangle{
    int length;
    int breadth;
};
void fun1(struct Rectangle *r){
    r->length = 20;
    cout<<"Length : "<<r->length<<endl<<"Breadth : "<<r->breadth<<endl;
}
void fun(struct Rectangle r){
    r.length = 20;
    cout<<"Length : "<<r.length<<endl<<"Breadth : "<<r.breadth<<endl;
}
struct Rectangle* fun2(){
    struct Rectangle *p;
    p = (struct Rectangle*)malloc(sizeof(struct Rectangle));
    p->length = 28;
    p->breadth = 35;

    return p;

}
int main() {
    struct Rectangle r = {10,5};
    fun(r);
    printf("length : %d\nBreadth : %d\n",r.length,r.breadth); 
    fun1(&r);  
    printf("length : %d\nBreadth : %d\n",r.length,r.breadth);          
    struct Rectangle *q = fun2();
    printf("length : %d\nBreadth : %d\n",q->length,q->breadth); 
    return 0;
}