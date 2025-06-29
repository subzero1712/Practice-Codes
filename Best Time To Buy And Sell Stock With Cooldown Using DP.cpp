//Memoization
class Solution {
public:
    int func(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(ind>=prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy==1){
            return dp[ind][buy] = max(-prices[ind]+func(ind+1, 0, prices, dp), 0+func(ind+1, 1, prices, dp));
        }else{
            return dp[ind][buy] = max(prices[ind]+func(ind+2, 1, prices, dp), 0+func(ind+1, 0, prices, dp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+2, vector<int>(2,-1));
        return func(0,1,prices,dp);
    }
};

//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    dp[i][buy]=max(-prices[i]+dp[i+1][0], 0+dp[i+1][1]);
                }else{
                    dp[i][buy]=max(prices[i]+dp[i+2][1], 0+dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};

//Space Optimisation
//Using 3 Arrays
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> front2(2,0);
        vector<int> front1(2,0);
        vector<int> curr(2,0);
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    curr[buy]=max(-prices[i]+front1[0], 0+front1[1]);
                }else{
                    curr[buy]=max(prices[i]+front2[1], 0+front1[0]);
                }
            }
            front2=front1;
            front1=curr;
        }
        return curr[1];
    }
};
