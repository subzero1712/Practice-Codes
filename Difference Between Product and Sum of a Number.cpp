#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int digit;
    int answer;
    int sum=0;
    int prod=1;
    while(n!=0)
    {
        digit=n%10;
        sum=sum+digit;
        prod=prod*digit;
        n=n/10;
        
    }
    answer=prod-sum;
    cout<<answer;
}
