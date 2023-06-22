#include <iostream>
#include <limits.h>

using namespace std;
int getmax(int arr[], int size)
{
    int max= INT_MIN;
    int i;
    for(i=0;i<size;i++){
        if(arr[i]>max){
            max= arr[i];
        }
        
    }
    return max;
}
int getmin(int arr[], int size)
{
    int min= INT_MAX;
    int i;
    for(i=0;i<size;i++){
        if(arr[i]<min){
            
            min= arr[i];
        }
    }
    return min;
}
int main()
{
    int size;
    
    int i;
    cin>>size;
    int arr[10];
    for(i=0;i<size;i++){
        cin>>arr[i];
        
    }
    cout<<"maximum element is "<< getmax(arr, size)<< " minimum element is "<< getmin(arr, size);
}
