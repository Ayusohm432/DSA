#include <iostream>
using namespace std;
struct Rectangle{
    int length;
    int breadth;
};
int main() {
    struct Rectangle r ={10,5}; 
    struct Rectangle *ptr = &r;

 
    // r.length=30;
    //ptr->length=30;
    (*ptr).length=30;

    //Dynamic declaration of Rectangle Structure. 
    struct Rectangle *p;
    // p = new Rectangle;
    p = (struct Rectangle*)malloc(sizeof(struct Rectangle));
    p->length = 20;
    p->breadth = 40; 

    cout<<"Length : "<<p->length<<endl;
    cout<<"Breadth : "<<p->breadth;

           
    return 0;
}