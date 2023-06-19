#include <iostream>

using namespace std;

int main()
{
    int n;
    int i=1;
    int sum=0;
    cin>>n;
    while(i!=n+1)
    {
        cout<<i<<endl;
        sum=sum+i;
        
        i=i+1;
        
        
    }
    cout<<"sum"<<sum<<endl;
    return 0;
}
