// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class base{
    int x;
    int y;
    
    public:
    static int obj_cnt;
    int p; int q;
   
    base(int x, int y) :x(x), y(y){
        p=1000, q=2000;
       obj_cnt++;
        cout << "BASE Constructor called"<<endl;
        cout<<" # of objects: "<<obj_cnt<<endl;
    }
    
    /* static func get_obj_cnt can access only obj_cnt; not p and q, since p and q not declared as static*/
    static int get_obj_cnt(){
        return obj_cnt;
    }
    
    /*const functions are allowed to read data variables but not modify them */
    int print_vals() const{
        cout<<"x:"<<x<<" y:"<<y<<" p:"<<p<<" q:"<<q<<endl;
        return x+y+p+q;
    }
    
    int getval_not_virtual_x(){
      //  obj_cnt++;
        cout<<"not virtual base x: ";
        return x;
    }
    
    int getval_not_virtual_y(){
        cout<<"not virtual base y: ";
        return y;
    } 
    
    virtual int getval_x(){
        cout<<"base get_X x: "<<x<<"base y: "<<y<<" ret x:";
        return x;
    } 
    virtual int getval_y() {
        cout<<"base get_y Y: "<<y<<"base x: "<<x<<endl;
        return y;
    }
    
    virtual ~base(){
         obj_cnt--;
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
        cout<<"calling base getval_x: "<<base::getval_x(); //here we called base getval_x from derived class
        a1=7772;
        cout<<"\n new a1: ";
        return a1;
    }
    
     int getval_y() {
        cout<<getval_not_virtual_y()<<" q:"<<q<<endl;
        b1=8822;
        cout<<"new b1: ";
        return b1;
    }
    ~derived(){
        obj_cnt--;
        cout<<endl<<"derived deleted"<<endl;
    }
};


int base::obj_cnt = 0;


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
    int sum=b2->print_vals();
    cout<<endl<<"sum: "<<sum;
    cout<<"\n\n-------deleting b2---------";
    delete b2;
    
    const base b3= base(100,200);
   /* b3.getval_x();   b3.getval_y(); */ //will show error here since getval_x and getval_y are not const
   int sum3=b3.print_vals(); //will not show error since print_vals is declared as const
   cout<<endl<<"sum3: "<<sum3;
    
    cout<<endl<<"derived class pointer-> derived class object"<<endl;
    derived *d2= new derived(97,99);
    d2->p=78394; d2->q=88727; //derived class inherited public p and q from base class. hence we can access and modify q,q;
    d2->getval_x();   d2->getval_y();
    cout<<"\n\n----deleting d2-----";
    delete d2;
    cout<<"number of objects: "<<base::obj_cnt;
     cout<<"\n number of objects from static func: "<<base::get_obj_cnt();
    
    // Write C++ code here
    std::cout << "\nTry programiz.pro\n";

    return 0;
}
