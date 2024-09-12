//Better Approach
#include<vector>

int getSingleElement(vector<int> &arr){
	int n=arr.size();
	int maxi=arr[0];
	for(int i=0;i<n;i++){
		maxi=max(maxi,arr[i]);
	}	
	int hash[maxi+1]={0};
	for(int i=0;i<n;i++){
		hash[arr[i]]++;
	}
	for(int i=0;i<n;i++){
		if(hash[arr[i]]==1){
			return arr[i];
		}
	}
	return -1;
}
//2nd Better Approach
#include<vector>
#include<map>

int getSingleElement(vector<int> &arr){	
map<int, int> mpp;
int n=arr.size();
for(int i=0;i<n;i++){
	mpp[arr[i]]++;
}
for(auto it:mpp){
	if(it.second==1){
		return it.first;
	}
 }
}
//Optimal Approach
#include<vector>

int getSingleElement(vector<int> &arr){
	int xor1 = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        xor1 = xor1 ^ arr[i];
    }
    return xor1;
}
