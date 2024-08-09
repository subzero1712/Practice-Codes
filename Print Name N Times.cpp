#include <iostream>
using namespace std;
void print(int i,int n){
    if(i>n){
        return;
    }
    cout<<"palak"<<endl;
    print(i+1,5);
}
int main()
{
    int i=1;
    int m=5;
    print(i,m);
}
