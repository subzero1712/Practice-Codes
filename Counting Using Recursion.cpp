#include <iostream>

using namespace std;
void print(int n)
{
    if(n==0)
    {
        return ;
    }
    cout<<n<<endl;
    print(n-1);
}
int main()
{
    
    int n;
    cin>>n;
    //jab value return hi nahi hori to kisi variable mn assign bhi nahi ho skti
    print(n);
    return 0;
}
