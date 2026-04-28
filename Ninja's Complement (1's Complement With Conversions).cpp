#include <bits/stdc++.h> 
int cnvrtB2D(string &str)
{
	int N=str.length();
    int p2=1;
    int res=0;
    for(int i=N-1;i>=0;i--){
        if(str[i]=='1'){
            res+=p2;
        }
        p2=p2*2;
    }
    return res;
}
string cnvrtD2B(int n)
{	
	if(n=='0') return "0";
	string res="";
	while(n!=0){
		if(n%2==1){
			res+='1';
		}
		else{
			res+='0';
		}
		n=n/2;
	}
	res+='1';
	reverse(res.begin(), res.end());
	return res;
}
int ninjaComplement(int n) 
{
	if(n==0) return 1;
	string n1=cnvrtD2B(n);
	string comp;
	for(int i=0;i<n1.length();i++){
		if(n1[i]=='1'){
			comp+='0';
		}
		else{
			comp+='1';
		}
	}
	int ans=cnvrtB2D(comp);
	return ans;
}
