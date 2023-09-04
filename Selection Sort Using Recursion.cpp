#include <iostream>
using namespace std;
void sorted(int arr[],int s,int n)
{
    if(s>=n-1)
    {
        return;
    }
    int min=s;
    for (int i=s;i<n;i++)
    {
        if(arr[i]<arr[min])
        {
            min=i;
        }
    }
    int temp=arr[s];
    arr[s]=arr[min];
    arr[min]=temp;
    sorted(arr,s+1,n);
    
}


int main()
{
    int arr[5]={8,6,4,3,1};
    sorted(arr,0,5);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
}
