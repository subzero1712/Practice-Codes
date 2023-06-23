#include <iostream>

using namespace std;

int  getpivot(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s)/2;
    while(s<e)
    {
        if(arr[mid] >= arr[0]){
            s =  mid + 1; 
            }
        else{
                e = mid;
            }
        mid = s + (e - s)/2;
            
    }
    return s;
    
}
int binarysearch(int arr[], int s, int e, int key){
     int start=s;
     int end1= e;
     int mid= (start + (end1 - start)/2);
     while(start<=end1){
         if(arr[mid]==key){
             
             return mid;
         }
         if(key>arr[mid]){
             
             start= mid + 1;
         }
         
         else{
             end1= mid - 1;
         }
         
         mid= (start + (end1 - start)/2);
      
         
     }
     
     return -1;
}

int getposition( int arr[], int n, int key)
{ 
    
    int pivot = getpivot(arr, n);
    if(key>=arr[pivot] && key<=arr[n - 1])
    {
        return binarysearch(arr, pivot, n - 1, key);
    }
    else
    {
        return binarysearch(arr, 0, pivot - 1 , key );
    }
    
}
int main()
{
    int arr[5] = {7, 8, 1, 2, 3};
    cout<< getposition(arr, 5, 1);
}
