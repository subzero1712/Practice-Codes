#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	int res=1;
	while(n>0)
	{
          // odd check krne ka tareeka
          if (n & 1) {
            res = (1LL*(res) * (x)%m)%m;
          }
		  //we did not write this in if block because it is common for both cases 
		  x=( 1LL * (x)%m*(x)%m)%m;
      // n/2 karne ka tareeka hai
	      n=n>>1;
    }
	return res;
	
}
