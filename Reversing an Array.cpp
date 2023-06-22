#include <iostream>

using namespace std;

int reverse(int arr[], int size)
{
    int start=0;
    int end=(size-1);
    while(start<=end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }


    
}
int printarray(int arr[], int size)
{
    int i;
    for(i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[6]={1,4,0,8,-9,5};
    int brr[5]={7,9,3,2,4};
    reverse(arr,6);
    reverse(brr,5);
    printarray(arr,6);
    printarray(brr,5);
    
    
    
}
