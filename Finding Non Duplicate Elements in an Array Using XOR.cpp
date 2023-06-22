#include <iostream>

using namespace std;

int main()
{
    int arr[9]={1, 2, 1, 2, 3, 4, 3, 5, 5};
    int ans=0;
    int i;
    //using the concept of XOR
    for(i=0;i<9;i++){
        ans=ans^arr[i];
    }
    cout<<ans;
}
