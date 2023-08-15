#include <iostream>

using namespace std;

void update(int *a, int *b)
{
    int sum= *a + *b;
    int diff= *a - *b;
    cout<<sum<<endl;
    if(diff<0)
    {
        cout<<abs(diff);
    }
    else
    {
        cout<<diff;
    }
    
    
}
int main()
{
    int a;
    int b;
    cin>>a>>b;
    update(&a, &b);
    
}
