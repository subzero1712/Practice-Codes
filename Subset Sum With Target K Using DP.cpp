//Memoization
#include <bits/stdc++.h> 
bool func(int k, vector<int>& arr, int ind, vector<vector<int>>& dp){
    if(k==0) return true;
    if(ind==0) return arr[0]==k;

    if(dp[ind][k]!=-1) return dp[ind][k];

    bool not_take=func(k,arr,ind-1,dp);
    bool take=false;
    if(k>=arr[ind]){
        take=func(k-arr[ind],arr,ind-1,dp);
    }
    return dp[ind][k]=(take||not_take);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1,-1));
    return func(k,arr,n-1,dp);
}

//Tabulation
#include <bits/stdc++.h> 
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++) dp[i][0] = true;  // sum 0 is always possible (empty subset)
    if (arr[0] <= k) dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int target = 1; target <= k; target++) {
            bool not_take = dp[i - 1][target];
            bool take = false;
            if (target >= arr[i])
                take = dp[i - 1][target - arr[i]];
            dp[i][target] = take || not_take;
        }
    }

    return dp[n - 1][k];
}

//Space Optimised
#include <bits/stdc++.h> 
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1,0);
    vector<bool> curr(k+1,0);
    prev[0]=true;
    curr[0] = true;  
    if (arr[0] <= k) prev[arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int target = 1; target <= k; target++) {
            bool not_take = prev[target];
            bool take = false;
            if (target >= arr[i])
                take = prev[target - arr[i]];
            curr[target] = take || not_take;
        }
        prev=curr;
    }

    return prev[k];
}

