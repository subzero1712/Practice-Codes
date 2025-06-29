//Memoization
class Solution {
public:
int func(int ind, int buy, int fee, vector<int>& prices, vector<vector<int>>& dp){
    if(ind==prices.size()) return 0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    if(buy==1){
        return dp[ind][buy] = max(-prices[ind]+func(ind+1,0,fee,prices,dp), func(ind+1,1,fee,prices,dp));
    }else{
        return dp[ind][buy] = max((prices[ind]+func(ind+1,1,fee,prices,dp))-fee, func(ind+1,0,fee,prices,dp));
    }
}
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        return func(0,1,fee,prices,dp);
    }
};

//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    dp[i][buy]=max(-prices[i]+dp[i+1][0], 0+dp[i+1][1]);
                }else{
                    dp[i][buy]=max(prices[i]+dp[i+1][1]-fee, 0+dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};

//Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> prev(2,0);
        vector<int> curr(2,0);
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    curr[buy]=max(-prices[i]+prev[0], 0+prev[1]);
                }else{
                    curr[buy]=max(prices[i]+prev[1]-fee, 0+prev[0]);
                }
            }
            prev=curr;
        }
        return prev[1];
    }
};
