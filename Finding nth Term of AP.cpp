#include <iostream>

using namespace std;
int theAP(int n)
{
    n=n*3+7;
    return n;
}
int main()
{
    int n;
    cin>>n;
    cout<<theAP(n);
}
