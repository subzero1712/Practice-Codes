#include <iostream>
using namespace std;
void sum1(int i, int n){
    if(i<1){
        cout<<"the sum is: "<<n<<endl;
        return;
    }
    sum1(i-1,n+i);
}

int main()
{
    int n;
    cout<<"Enter the Number: "<<endl;
    cin>>n;
    sum1(n, 0);
}
