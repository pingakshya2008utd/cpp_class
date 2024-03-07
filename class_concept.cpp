// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class base{
    int x;
    int y;
   
    public:
    int p; int q;
    base(int x, int y) :x(x), y(y){
        p=1000, q=2000;
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
    
    virtual ~base(){
        cout<<"base deleted"<<endl;
    }
};

class derived: public base{
    int a1, b1;
    public:
    derived(int x, int y):base(x,y),a1(x), b1(y) {
        cout << "derived's Constructor called a1:"<<a1<<" b1:"<<b1<<endl;
    }
    
    int getval_x() {
        /*used getval_not_virtual_x to access pvt variables in base class, p and q public in base class and hence can be access directly*/
        cout<<getval_not_virtual_x()<<" p:"<<p<<endl; 
        a1=7772;
        cout<<"new a1: ";
        return a1;
    }
    
     int getval_y() {
        cout<<getval_not_virtual_y()<<" q:"<<q<<endl;
        b1=8822;
        cout<<"new b1: ";
        return b1;
    }
    ~derived(){
        cout<<endl<<"derived deleted"<<endl;
    }
};

int main() {
    cout<<endl<<"---derived class----"<<endl;
    derived d1(10,20);
    cout<<d1.getval_x()<<endl;
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
    b2->p=2222; b2->q=3333;
    b2->getval_x();   b2->getval_y();
    cout<<"\n\n-------deleting b2---------";
    delete b2;
    
    cout<<endl<<"derived class pointer-> derived class object"<<endl;
    derived *d2= new derived(97,99);
    d2->p=78394; d2->q=88727; //derived class inherited public p and q from base class. hence we can access and modify q,q;
    d2->getval_x();   d2->getval_y();
    cout<<"\n\n----deleting d2-----";
    delete d2;
     
     
    
    // Write C++ code here
    std::cout << "\nTry programiz.pro\n";

    return 0;
}
