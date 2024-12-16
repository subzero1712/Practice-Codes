#include<math.h>
int count(int n){
	int cnt=(int)(log10(n)+1);
	return cnt;
}
int pow(int n, int k){
	int res=1;
	for(int i=0;i<k;i++){
		res=res*n;
	}
	return res;
}
bool checkArmstrong(int n){
	int k=count(n);
	int armstrong=0;
	int original=n;
	while(n>0){
		int last = n%10;
		armstrong = armstrong+pow(last,k);
		n=n/10;
	}
	if(armstrong==original){
		return true;
	}
	else{
		return false;
	}
    
}
