#include <iostream>
#include <math.h>

using namespace std;

int main()
{
   int n;
   int i;
   int x;
   cin>>n;
   int m;
   for(i=0;i<=31;i++){
    m = pow(2,i);
   
   
    if(n==m)
    {
        cout<<"true";
        break;
    }
   
    
   
   }
   if(n!=m)
   {
       cout<<"false";
   }
   
}
