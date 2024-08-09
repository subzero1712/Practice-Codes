#include <iostream>
using namespace std;
void print(int i,int n){
    if(i>n){
        return;
    }
    print(i+1,4);
    cout<<i<<endl;
}
int main()
{
    int i=1;
    int m=4;
    print(i,m);
}
