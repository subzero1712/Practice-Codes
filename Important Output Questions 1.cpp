#include <iostream>

using namespace std;

void update(int a)
{
    a=a/10;
}
int main()
{
    int a=20;
    update(a);
    cout<<a<<endl;
}
