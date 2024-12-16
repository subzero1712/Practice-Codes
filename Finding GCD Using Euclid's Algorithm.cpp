int gcd(int a,int b)
{
	int gcd=1;
	for(int i=1;i<=min(a,b);i++){
		if(a%i==0 && b%i==0){
			gcd=i;
		}
	}
	return gcd;
}
//2nd Approach
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if(a==0)
    {
        return b;
    }
    if(b==0)
    {
        return a;
    }
    while(a!=b)
    {
        if(a>b)
        {
            a=a-b;
        }
        else
        {
            b=b-a;
        }
        
    }
    return a;
}
int main()
{
    int a;
    int b;
    cout<<"enter value of a and b ";
    cin>>a>>b;
    int ans=gcd(a,b);
    cout<<"gcd of "<<a<<" and "<<b<<" is "<<ans;
}
//3rd Approach
int gcd(int a,int b)
{
	while(a>0 && b>0){
		if(a>b){
			a=a%b;
		}
		else{
			b=b%a;
		}
	}
	if(a==0){
			return b;
		}
	else{
			return a;
		}
}
