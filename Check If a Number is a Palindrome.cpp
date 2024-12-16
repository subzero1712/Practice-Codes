int reverse(int n){
	int reverse=0;;
	while(n>0){
		int last=n%10;
		reverse=(reverse*10)+last;
		n=n/10;
	}
	return reverse;
}
bool palindrome(int n)
{
    if(reverse(n)==n){
        return true;
    }
    else{
        return false;
    }
}
