int countDigits(int n){
	int cntDigits=0;
	while(n!=0){
		n=n/10;
		cntDigits++;
	}	
	return cntDigits;
}
