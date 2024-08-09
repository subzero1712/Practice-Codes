#include <iostream>
using namespace std;
void print(int i,int n){
    if(i<1){
        return;
    }
    print(i-1,4);
    cout<<i<<endl;
}
int main()
{
    int i=4;
    int m=4;
    print(i,m);
}
