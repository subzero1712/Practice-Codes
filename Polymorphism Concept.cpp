#include <iostream>

using namespace std;
class check{
    public:
    void poly(){
        cout<<"check 1"<<endl;
    }
    void poly(int a){
        cout<<"check 2"<<endl;
    }
    void poly(int a, int b)
    {
        cout<<"check 3"<<endl;
    }
};
int main()
{
    check ob;
    ob.poly();
    ob.poly(2);
    ob.poly(1,2);
}
