#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"enter first number";
    cin>>n;
    int m;
    cout<<"enter second number";
    cin>>m;
    char op;
    cout<<"enter operation";
    cin>>op;
    switch(op){
    case '+': cout<<"the answer is:"<<n+m<<endl;
              break;
    case '-': cout<<"the answer is"<<n-m<<endl;
              break;
    case '*': cout<<"the answer is"<<n*m<<endl;
              break;
    case '/': cout<<"the answer is"<<n/m<<endl;
              break;
              
    default: cout<<"enter the valid operation";
    }
}
