//Array
double minimiseMaxDistance(vector<int> &arr, int k){
	int n=arr.size();
	vector<int> howMany(n-1,0);
	for(int i=1;i<=k;i++){
		long double maxSec=-1;
		int maxInd=-1;
		for(int i=0;i<n-1;i++){
			long double diff=arr[i+1]-arr[i];
			long double sectionLen=diff/((long double)howMany[i]+1);
			if(maxSec<sectionLen){
				maxSec=sectionLen;
				maxInd=i;
			}
		}
		howMany[maxInd]++;
	}
	long double ans=-1;
	for(int i=0;i<n-1;i++){
		long double diff=arr[i+1]-arr[i];
		long double sectionLen=diff/((double)howMany[i]+1);
		ans=max(ans,sectionLen);
	}
	return ans;
}
//Priority Queue
#include "bits/stdc++.h"
double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<long double, int>> pq;

    for (int i = 0; i < n - 1; i++) {
        pq.push({arr[i + 1] - arr[i], i});
    }

    for (int gas = 1; gas <= k; gas++) {
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;
        howMany[secInd]++; // Corrected `howMany(secInd)` to `howMany[secInd]`
        long double inDiff = arr[secInd + 1] - arr[secInd];
        long double newSecLen = inDiff / ((long double)howMany[secInd] + 1);
        pq.push({newSecLen, secInd});
    }

    return pq.top().first;
}
//Binary Search
int number(long double dist, vector<int> &arr){
    int cnt=0;
    for(int i=1;i<arr.size();i++){
        int numberBtw=((arr[i]-arr[i-1])/dist);
        if((arr[i]-arr[i-1])/dist==numberBtw*dist){
            numberBtw--;
        }
        cnt+=numberBtw;
    }
    return cnt;
}
double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size(); // size of the array
    long double low = 0;
    long double high = 0;

    //Find the maximum distance:
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    //Apply Binary search:
    long double diff = 1e-6 ;
    while (high - low > diff) {
        long double mid = (low + high) / (2.0);
        int cnt = number(mid, arr);
        if (cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return high;
}
