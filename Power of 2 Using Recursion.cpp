#include <iostream>

using namespace std;
int power(int n)
{
    if(n==0)
    {
        return 1;
    }
    int chhoti=power(n-1);
    int badi=2*chhoti;
    return badi;
    
}
int main()
{
    int n;
    cin>>n;
    int ans=power(n);
    cout<<ans;
}
