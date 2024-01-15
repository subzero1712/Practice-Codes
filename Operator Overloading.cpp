#include <iostream>

using namespace std;
class op{
    public:
    int a;
    int b;
    void sum()
    {
        cout<<this->a + this->b;
        
    }
    void operator+(op &ob)
    {
        int value1=this->a;
        int value2=ob.b;
        cout<<"output "<<value1-value2<<endl;
    }
    void operator() (){
        cout<<this->a<<" "<<this->b<<endl;
    }
};
int main()
{
    op ob1, ob2;
    ob1.a=10;
    ob1.b=9;
    ob2.a=40;
    ob2.b=5;
    ob1+ob1; //operator 2 objects ke bich mein hi lgega
    ob1();
    ob2();
}
