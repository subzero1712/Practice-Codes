//Memoization
class Solution {
    public:
    int func(int ind, bool buy, vector<int>& prices, vector<vector<int>>& dp){
        if(ind==prices.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy){
            profit=max(-prices[ind]+func(ind+1,0,prices,dp),0+func(ind+1,1,prices,dp));
        }else{
            profit=max(prices[ind]+func(ind+1,1,prices,dp),0+func(ind+1,0,prices,dp));
        }
        return dp[ind][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        return func(0,1,prices,dp);
    }
};

//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));
        dp[n][1]=dp[n][0]=0;
        for (int i = n-1; i>=0; i--) {
            for (int j = 0; j <= 1; j++) {
                int profit = 0;
                if (j) {
                    profit = max(-prices[i] + dp[i+1][0],
                                 0 + dp[i+1][1]);
                } else {
                    profit = max(prices[i] + dp[i+1][1],
                                 0 + dp[i+1][0]);
                }
                dp[i][j] = profit;
            }
        }
        return dp[0][1];
    }
};

//Space Optimisation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);
        prev[1]=prev[0]=0;
        for (int i = n-1; i>=0; i--) {
            for (int j = 0; j <= 1; j++) {
                int profit = 0;
                if (j) {
                    profit = max(-prices[i] + prev[0],
                                 0 + prev[1]);
                } else {
                    profit = max(prices[i] + prev[1],
                                 0 + prev[0]);
                }
                curr[j] = profit;
            }
            prev=curr;
        }
        return prev[1];
    }
};

//4 Variable Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        long aheadBuy, aheadNotBuy, currBuy, currNotBuy;
        aheadNotBuy=aheadBuy=0;
        aheadBuy=aheadNotBuy=0;
        for (int i = n-1; i>=0; i--) {
                    currBuy = max(-prices[i] + aheadNotBuy,
                                 0 + aheadBuy);
                    currNotBuy = max(prices[i] + aheadBuy,
                                 0 + aheadNotBuy);
                aheadBuy=currBuy;
                aheadNotBuy=currNotBuy;
            }
        return aheadBuy;
    }
};
