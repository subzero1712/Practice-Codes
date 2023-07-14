#include <iostream>

using namespace std;

int main()
{
    int num = 5;
    int a = num;
    cout<<"num before change in a "<<num<<endl;
    a++;
    cout<<"num after change in a "<<num<<endl;
    
    
    int *p = &num;
    cout<<"before "<<num<<endl;
    (*p)++;
    cout<<"after "<<num<<endl;
    
    
    int *q = p;
    cout<<p<<" "<<q<<endl;
    cout<<*p<<" "<<*q<<endl;
    
    int i = 3;
    int *k = &i;
    *k = *k + 1;
    cout<<*k<<endl;
    cout<<"before k "<<k<<endl;
    k = k + 1;
    cout<<"after k "<<k<<endl;
}
