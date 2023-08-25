#include <iostream>

using namespace std;
bool linearsearch(int arr[], int size, int key)
{
    if(size==0)
    {
        return 0;
    }
    if(arr[0]==key)
    {
        return arr[0];
    }
    int remainingpart = linearsearch(arr + 1, size - 1,key);
    return remainingpart;
}
int main()
{
    int arr[10];
    int n,key;
    cout<<"enter the size of array and the element to be found "<<endl;
    cin>>n>>key;
    int i;
    cout<<"enter all the elements of an array "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(linearsearch(arr,n,key))
    {
        cout<<"yes, the element is present "<<endl;
    }
    else
    {
        cout<<"no element not present "<<endl;
    }
}
