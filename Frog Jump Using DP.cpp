//Memoization
#include <bits/stdc++.h> 
int jump(int ind, vector<int> &heights, vector<int> &dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int left=jump(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
    int right=INT_MAX;
    if(ind>1){
        right=jump(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);
    }
    return dp[ind]=min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return jump(n-1,heights,dp);
}

//Tabulation
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int fs=dp[i-1]+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1){
            ss=dp[i-2]+abs(heights[i]-heights[i-2]);
        }
        dp[i]=min(fs,ss);
    }
    return dp[n-1];
}
