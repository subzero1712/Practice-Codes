int countDigits(int n){
	int cntDigits=0;
	while(n!=0){
		n=n/10;
		cntDigits++;
	}	
	return cntDigits;
}
//2nd Approach
#include<math.h>
int countDigits(int n){
	int cnt=(int)(log10(n)+1);
	return cnt;
}
