#include <iostream>

using namespace std;
int binarysearch(int arr[],int s,int e,int k)
{
    if(s>e)
    {
        return false;
    }
    int mid = s+(e-s)/2;
    if(arr[mid]==k)
    {
        return true;
    }
    if(arr[mid]<k)
    {
        return binarysearch(arr,mid + 1,e,k);
    }
    else
    {
        return binarysearch(arr,s,mid - 1,k);
    }
}
int main()
{
    int arr[10];
    int n,k;
    cout<<"enter the size of array and the element to be searched "<<endl;
    cin>>n>>k;
    cout<<"enter the elements of array "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=binarysearch(arr,0,n,k);
    if(ans)
    {
        cout<<"element is present "<<endl;
    }
    else
    {
        cout<<"element is not present "<<endl;
    }
}
