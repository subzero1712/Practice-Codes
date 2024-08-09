#include <iostream>
using namespace std;
bool palindrome(char arr[], int n, int i){
    if(i>=n/2){
        return true;
    }
    if(arr[i]!=arr[n-i-1]){
        return false;
    }
    palindrome(arr, n, i+1);
}
int main()
{
    int n;
    cout<<"enter size of array"<<endl;
    cin>>n;
    char arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"checking for palindrome: "<<palindrome(arr, n, 0);
}
