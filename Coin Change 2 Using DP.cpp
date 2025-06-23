//Memoization
class Solution {
    public:
    int func(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(ind==0){
            return (amount%coins[ind]==0);
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int not_take=func(ind-1,amount,coins,dp);
        int take=0;
        if(coins[ind]<=amount) take=func(ind,amount-coins[ind], coins, dp);

        return dp[ind][amount]=take+not_take;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return func(coins.size()-1,amount,coins,dp);
    }
};

//Tabulation
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            dp[0][i]=(i%coins[0]==0);
        }
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                long long not_take=dp[i-1][j];
                long long take=0;
                if(coins[i]<=j) take=dp[i][j-coins[i]];
                dp[i][j]=take+not_take;
            }
        }
        return (int)dp[coins.size()-1][amount];
    }
};

//Space Optimisation
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);
        for(int i=0;i<=amount;i++){
            prev[i]=(i%coins[0]==0);
        }
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                long long not_take=prev[j];
                long long take=0;
                if(coins[i]<=j) take=curr[j-coins[i]];
                curr[j]=take+not_take;
            }
            prev=curr;
        }
        return (int)prev[amount];
    }
};
