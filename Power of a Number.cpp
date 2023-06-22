#include <iostream>

using namespace std;

int main()
{
   int a;
   int b;
   int i;
   cin>>a>>b;
   int  ans=1;
   for(i=1;i<=b;i++)
   {
       ans=ans*a;
   }
   cout<<ans;
}
