#include <iostream>

using namespace std;
int firstOcc(int arr[], int n, int key){
    int s=0;
    int e= n-1;
    int mid= s+(e-s)/2;
    int ans  = -1;
    while(s<=e){
        
        if(arr[mid]== key){
            ans = mid;
            e = mid - 1;
        }
        else if(key>arr[mid]){
            s = mid + 1;
        }
        else  if(key<arr[mid]){
            e= mid - 1;
        }
        
        mid= s + (e-s)/2;
        
    }
    
    return ans;
}

int lastOcc(int arr[], int n, int key){
    int s=0;
    int e= n - 1;
    int mid= s+(e-s)/2;
    int ans= - 1;
    while(s<=e){
        
        if(key==arr[mid]){
            ans=mid;
            s = mid + 1;
        }
        else if(key<arr[mid]){
            e = mid - 1;
        }
        else if(key>arr[mid]){
            s = mid + 1;
        }
        mid= s + (e-s)/2;
        
    }
    return ans;
}
int main()
{
    int even[10]={1, 2, 3, 3, 3, 3, 3, 3, 4, 5};
    int odd[9]={1,2,3,3,4,4,4,4,5};
    cout<<"the first occurrence of key is " << firstOcc(even, 10, 3)  << endl;
    cout<<"the first occurrence of key is " << lastOcc(even, 10, 3)<<endl;
    
    
    
}

