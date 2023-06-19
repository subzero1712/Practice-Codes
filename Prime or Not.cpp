*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
   int n;
   cout<<"enter a number";
   cin>>n;
   int i;
   bool isprime=1;
   for(i=2;i<n;i++)
   {
       if(n%i==0)
       {
           isprime=0;
           break;
       }
       
       
   }
   if(isprime==0)
   {
       cout<<" not a prime number";
   }
   else
   {
       cout<<"prime number";
   }
}
