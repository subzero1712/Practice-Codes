#include <iostream>

using namespace std;


int getsum(int *arr, int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    return sum;
    
}
int main()
{
    int n;
    cin>>n;
    //int type ka dynamic n variable create ho gaya array ki size ke liye
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=getsum(arr,n);
    cout<<"the sum is "<<ans<<endl;
}
