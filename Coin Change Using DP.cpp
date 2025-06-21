//Memoization
class Solution {
public:
int func(int ind, vector<int>& coins, int T, vector<vector<int>>& dp){
    if(ind==0){
        if(T%coins[ind]==0) return T/coins[ind];
        else return 1e9;
    }
    if(dp[ind][T]!=-1) return dp[ind][T];
    int not_take=0+func(ind-1,coins,T,dp);
    int take=1e9;
    if(coins[ind]<=T) take=1+func(ind,coins,T-coins[ind],dp);
    return dp[ind][T]=min(take, not_take);
}
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans=func(coins.size()-1,coins,amount,dp);
        return ans >= 1e9 ? -1 : ans;
    }
};

//Tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
            else dp[0][i]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int not_take=0+dp[i-1][j];
                int take=1e9;
                if(coins[i]<=j) take=1+dp[i][j-coins[i]];
                dp[i][j]=min(take, not_take);
            }
        }
        int ans=dp[n-1][amount];
        return ans>=1e9?-1:ans;
    }
};

//Space Optimisation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) prev[i]=i/coins[0];
            else prev[i]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int not_take=0+prev[j];
                int take=1e9;
                if(coins[i]<=j) take=1+curr[j-coins[i]];
                curr[j]=min(take, not_take);
            }
            prev=curr;
        }
        int ans=prev[amount];
        return ans>=1e9?-1:ans;
    }
};
