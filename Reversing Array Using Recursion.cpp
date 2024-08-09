#include <iostream>
using namespace std;
void reverse(int i, int arr[], int n){
    if(i>=n/2){
        return;
    }
    int temp = arr[i];
    arr[i]=arr[n-i-1];
    arr[n-i-1]=temp;
    reverse(i+1,arr,n);
    
}
int main()
{
    int arr[5] = {1,2,3,4,5};
    int i=0;
    reverse(i,arr, 5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}
