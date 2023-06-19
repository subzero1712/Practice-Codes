#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a=0;
    int b=1;
    cout<<a<<" "<<b;
    int i;
    for(i=0;i<=n;i++)
    {
        int nextnumber= a + b;
        cout<<" "<<nextnumber;
        a=b;
        b= nextnumber;
    }
}
