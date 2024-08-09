#include <iostream>
using namespace std;
int sum1(int n){
    if(n==0){
        return 0;
    }
    return n+sum1(n-1);
}

int main()
{
    int n;
    cout<<"Enter the Number: "<<endl;
    cin>>n;
    cout<<sum1(n);
}
