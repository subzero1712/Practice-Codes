
#include <iostream>

using namespace std;

int binarysearch(int arr[], int size, int key){
     int start=0;
     int end1= size-1;
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

int main()
{
    int even[6]={2,4,6,8,12,18};
    int odd[5]={3,8,11,14,16};
    int evenindex= binarysearch(even, 6, 12);
    cout<<"the index of key is"<<evenindex<<endl;
    int oddindex=  binarysearch(odd, 5, 3);
    cout<<"the index of key is"<<oddindex<<endl;
}

