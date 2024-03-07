// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class base{
    int x;
    int y;
    public:
    
    
    base(int x=9, int y=6) :x(x), y(y){
          cout << "BASE Constructor called"<<endl;
    }
    
    int getval_not_virtual_x(){
        cout<<"not virtual base x: ";
        return x;
    }
    
    int getval_not_virtual_y(){
        cout<<"not virtual base y: ";
        return y;
    } 
    
    virtual int getval_x(){
        cout<<"base get_X x: "<<x<<"base y: "<<y<<endl;
        return x;
    } 
    virtual int getval_y() {
        cout<<"base get_y Y: "<<y<<"base x: "<<x<<endl;
        return y;
    }
};

class derived: public base{
    int a1, b1;
    public:
    derived(int x, int y):base(x,y) {
        a1=x; b1=y;
        cout << "derived's Constructor called a1:"<<a1<<" b1:"<<b1<<endl;
    }
    
    int getval_x() {
        cout<<getval_not_virtual_x()<<": ";
        return a1;
    }
    
     int getval_y() {
         cout<<getval_not_virtual_y()<<endl;
         return b1;
    }
};

int main() {
    cout<<endl<<"---derived class----"<<endl;
    derived d1(10,20);
    cout<<d1.getval_x();
    d1.getval_y();
    cout<<endl<<"---base class----"<<endl;
    base b1(60,90);
    b1.getval_x();
    b1.getval_y();
    
    cout<<endl<<"base class pointer-> base class object"<<endl;
    base *b2= new base(31,41);
    b2->getval_x();   b2->getval_y();
    
    cout<<endl<<"base class pointer-> derived class object"<<endl;
    b2= new derived(51,61);
    b2->getval_x();   b2->getval_y();
     
     
    
    // Write C++ code here
    std::cout << "Try programiz.pro";

    return 0;
}
