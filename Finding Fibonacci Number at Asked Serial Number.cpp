#include <iostream>

using namespace std;

int fibonacci(int n){
    int a=0;
    int fib;
    int b=1;
    int i;
    for(i=1;i<n;i++)
    {
    fib=a+b;
    a=b;
    b=fib;
    }
    return a;

}
int main(){
    int n;
    cin>>n;
    cout<<(fibonacci(n));
}



