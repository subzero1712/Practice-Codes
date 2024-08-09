#include <iostream>
using namespace std;
bool palindrome(string &arr, int n, int i){
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
    string s = "madom";
    cout<<"checking for palindrome: "<<palindrome(s, n, 0);
}
