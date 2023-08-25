#include <iostream>

using namespace std;
bool isSorted(int arr[], int size)
{
    if(size==0||size==1)
    {
        return true;
    }
    if(arr[0]>arr[1])
    {
        return false;
    }
    else
    {
        int remainingterm = isSorted(arr + 1,size - 1);
        return remainingterm;
    }
    
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
    int ans = isSorted(arr,n);
    cout<<ans;
    
}
