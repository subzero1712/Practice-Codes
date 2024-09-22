//Better Approach
#include<map>
int majorityElement(vector<int> v) {
	map<int,int> mpp;
	int n=v.size()/2;
	for(int i=0;i<v.size();i++){
		mpp[v[i]]++;
	}
	for(int i=0;i<mpp.size();i++){
		if(mpp[v[i]]>n){
			return v[i];
		}
	}
return -1;
/*
for(auto it:mpp){
		if(it.second>n){
			return it.first;
*/
}
//optimal Approach
int majorityElement(vector<int> v) {
	int cnt=0;
	int el;
	for(int i=0;i<v.size();i++){
		if(cnt==0){
			cnt=1;
			el=v[i];
		}
		else if(el==v[i]){
			cnt++;
		}
		else{
			cnt--;
		}
	}
	int cnt1=0;
	for(int i=0;i<v.size();i++){
		if(el==v[i]) cnt1++;
		if(cnt1>(v.size()/2)){
			return el;
		}
	}
	return -1;
}
