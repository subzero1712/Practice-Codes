#include <iostream>
#include<limits.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ans=0;
    int digit;
    while(n!=0)
    {
    digit=n%10;
    if((ans>INT_MAX/10)||(ans<INT_MIN/10))
    {
        cout<<"0";
    }
    ans=ans*10+digit;
    n=n/10;
    
    }
    cout<<ans;
}
