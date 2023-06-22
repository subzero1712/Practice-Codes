#include <iostream>

using namespace std;

int update(int a)
{
    int ans;
    ans=a*a;
    return ans;
}
int main()
{
    int a=14;
    a=update(a);
    cout<<a<<endl;
}
