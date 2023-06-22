#include <iostream>


using namespace std;

int swapalternate(int arr[], int size)
{
    int i;
    for(i=0;i<size;i+=2){
        if(i+1 <size){
            swap(arr[i], arr[i+1]);
        }
    }
}
void getarray(int arr[], int size)
{
    int i;
    for(i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int even[6]={4,7, 9, -2, -9, 5};
    int odd[5]={7, 4, 90, 3, 8};
    swapalternate(even, 6);
    getarray(even, 6);
    swapalternate(odd, 5);
    getarray(odd, 5);
    return 0;
}

