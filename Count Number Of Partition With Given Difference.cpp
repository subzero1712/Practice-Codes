//Space Optimisation
#include <bits/stdc++.h> 
int findWays(vector<int>& arr, int k)
{
    const int mod = 1e9 + 7;
    int n = arr.size();
    vector<int> prev(k+1,0);
    vector<int> curr(k+1,0);
    prev[0]=curr[0] = 1;

    if (arr[0] == 0) prev[0] = 2;
    else if (arr[0] <= k) prev[arr[0]] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= k; j++){
            int not_pick = prev[j];
            int pick = 0;
            if(arr[i] <= j) pick = prev[j - arr[i]];
            curr[j] = (pick + not_pick)%mod;
        }
        prev=curr;
    }
    return prev[k];
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totSum=0;
    for(auto &it: arr){
        totSum+=it;
    }
    //we are checking for it to be not odd because if it is odd
    //then totSum-d will give fraction value which we do not want
    if(totSum-d<0 || (totSum-d)%2) return 0;
    int target=(totSum-d)/2;
    return findWays(arr,target);
}

//We can use tabulation and memoization as well, just change the findWays code from SO to memoization or tabulation
