#include <iostream>

using namespace std;
class animal{
    public:
    int age;
    int weight;
    
};
class dog: public animal{
  int palak=1;
};
int main()
{
    dog ob1;
    cout<<ob1.age;
    cout<<ob1.weight;
}
