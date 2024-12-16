#include<iostream>
using namespace std;
bool prime(int n){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(n%i==0){
			cnt++;
		}
	}
	if(cnt==2){
		return true;
	}
	else{
		return false;
	}
}
int main() {
	int n;
	cin>>n;
	if(prime(n)){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
}
//2nd Approach
#include<iostream>
using namespace std;
int prime(int n){
	int cnt=0;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			cnt++;
			if((n/i)!=i){
				cnt++;
			}
		}
	}
	if(cnt==2){
		return true;
	}
	else{
		return false;
	}
}
int main() {
	int n;
	cin>>n;
	if(prime(n)){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
	
}
