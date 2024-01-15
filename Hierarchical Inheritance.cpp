#include <iostream>

using namespace std;
class A{
    public:
    void func1(){
        cout<<"function 1 "<<endl;
    }
    
};
class B: public A{
    public:
    void speak()
    {
        cout<<"Speaking"<<endl;
    }
};
class C: public A{
    public:
    void hyb()
    {
        cout<<"Barking and Speaking"<<endl;
    }

};
int main()
{
    C ob1;
    B ob2;
    ob2.func1();
    ob2.speak();
    ob1.func1();
    ob1.hyb();
}
