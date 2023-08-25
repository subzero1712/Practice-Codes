#include <iostream>

using namespace std;
int getsum(int arr[],int size)
{
    if(size==0)
    {
        return 0;
    }
    if(size==1)
    {
        return arr[0];
    }
    int remainingpart=getsum(arr + 1, size - 1);
    int ans = arr[0] + remainingpart;
    return ans;
}
int main()
{
    int arr[10];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans = getsum(arr,n);
    cout<<"The sum is "<<ans;
}
    
