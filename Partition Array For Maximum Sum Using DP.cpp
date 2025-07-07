//Memoization
class Solution {
public:
    int func(int ind, vector<int>& arr, int k, vector<int>& dp){
        if(ind==arr.size()) return 0;
        int len=0;
        int maxi=INT_MIN;
        int maxAns=INT_MIN;
        if(dp[ind]!=-1) return dp[ind];
        for(int j=ind;j<min(ind+k,(int)arr.size());j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum=(len*maxi)+func(j+1,arr,k,dp);
            maxAns=max(maxAns,sum);
        }
        return dp[ind]=maxAns;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1,-1);
        return func(0,arr,k,dp);
    }
};

//Tabulation
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            int len=0;
            int maxi=INT_MIN;
            int maxAns=INT_MIN;
            //ye seedha chale ye ulta fark nahi padega
            for(int j=ind;j<min(ind+k,n);j++){
                len++;
                maxi=max(maxi,arr[j]);
                int sum=(len*maxi)+dp[j+1];
                maxAns=max(maxAns,sum);
            }
            dp[ind]=maxAns;
            }
        return dp[0];
    }
};
