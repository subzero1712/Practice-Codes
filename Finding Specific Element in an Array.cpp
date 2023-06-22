#include <iostream>

using namespace std;

bool search(int arr[], int size, int key)
{
    int i;
    for(i=0;i<size;i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}
int main()
{
    int key;
    cin>>key;
    int arr[10]={1, 23, 45, -75, -67, 23, 44, 12};
    
    bool found=search(arr, 10, key);
    if(found){
        cout<<"number is present";
    }
    else{
        cout<<"number is absent";
    }
}
