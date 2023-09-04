#include <iostream>

using namespace std;
void sorted(int arr[], int n)
{
    if(n<=1)
    {
        return;
    }
    sorted(arr, n-1);
    int last=arr[n-1];
    int j = n-2;
    while(j>=0 && arr[j]>last)
    {
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=last;
        
        
}
int main()
{
    int arr[5]={87,55,98,43,12};
    sorted(arr,5);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
}
