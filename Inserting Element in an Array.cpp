#include <iostream>

using namespace std;

int main()
{
    int arr[10], size, pos, element;
    int i;
    cout<<"enter size of array ";
    cin>>size;
    for(i=0;i<size;i++)
    {
        cout<<"enter the elements of an array";
        cin>>arr[i];
    }
    cout<<"enter the desired element and index at which it is to be added ";
    cin>>element>>pos;
    for(i=size - 1;i>=pos - 1;i--)
    {
        
        arr[i + 1]=arr[i];
        //i=i-1;
    }
    arr[pos - 1]=element;
    
    for(i=0;i<size+1;i++)
    {
        cout<<arr[i];
    }
    
    
}
