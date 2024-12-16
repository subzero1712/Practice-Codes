#include<iostream>
using namespace std;
int main() {
	int N;
	cin>>N;
	int reverse=0;;
	while(N>0){
		int last=N%10;
		reverse=(reverse*10)+last;
		N=N/10;
	}
	cout<<reverse;
}
