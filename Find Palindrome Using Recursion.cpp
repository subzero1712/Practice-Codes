#include <iostream>
using namespace std;
int palindrome(int n){
    if(n<=1){
        return n;
    }
    int last = palindrome(n-1);
    int slast = palindrome(n-2);
    return last + slast;
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<palindrome(n);
}
