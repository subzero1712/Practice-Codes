#include <iostream>

using namespace std;
void sorted(int *arr, int n)
{
    if(n==0||n==1)
    {
        return ;
    }
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
        
    }
    sorted(arr,n-1);
}
int main()
{
    int arr[10];
    int n;
    cout<<"enter size of array "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    sorted(arr,n);
    for(int i=0;i<n;i++)
    {
        
        cout<<arr[i]<<" ";
    }
}
