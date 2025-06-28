//Memoization
class Solution {
public:
    int func(int ind, int cap, int buy, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(cap==0) return 0;
        if(ind==prices.size()) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        int profit=0;
        if(buy){
            profit = max(-prices[ind]+func(ind+1, cap, 0, prices, dp), 0+func(ind+1, cap, 1, prices, dp));
        }else{
            profit = max(prices[ind]+func(ind+1, cap-1, 1, prices, dp), 0+func(ind+1, cap, 0, prices, dp));
        }
        return dp[ind][buy][cap]=profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2,vector<int>(3,-1)));
        return func(0, 2, 1, prices, dp);
    }
};

//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int profit=0;
                for(int k=1;k<=2;k++){
                    if(j){
                        profit = max(-prices[i]+dp[i+1][0][k], 0+dp[i+1][1][k]);
                    }else{
                        profit = max(prices[i]+dp[i+1][1][k-1], 0+dp[i+1][0][k]);
                    }
                    dp[i][j][k]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
};

//Space Optimisation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> prev(2, vector<int>(3,0));
        vector<vector<int>> curr(2, vector<int>(3,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int profit=0;
                for(int k=1;k<=2;k++){
                    if(j){
                        profit = max(-prices[i]+prev[0][k], 0+prev[1][k]);
                    }else{
                        profit = max(prices[i]+prev[1][k-1], 0+prev[0][k]);
                    }
                    curr[j][k]=profit;
                }
                prev=curr;
            }
        }
        return prev[1][2];
    }
};

//2nd Approach Memoization
class Solution {
public:
int func (int ind, int trans, vector<int>& prices, vector<vector<int>>& dp){
    if(ind==prices.size() || trans==4) return 0;
    if(dp[ind][trans]!=-1) return dp[ind][trans];
    if(trans%2==0){
        return dp[ind][trans]=max(-prices[ind]+func(ind+1,trans+1,prices,dp), func(ind+1,trans,prices,dp));
    }else{
        return dp[ind][trans]=max(prices[ind]+func(ind+1, trans+1, prices, dp), func(ind+1,trans,prices,dp));
    }
}
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(5,-1));
        return func(0,0,prices,dp);
    }
};

//2nd Approach Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(5, 0));

        for (int ind = n-1; ind >= 0; ind--) {
            for (int trans = 3; trans >= 0; trans--) {
                if (trans % 2 == 0) {
                    dp[ind][trans] = max(
                        -prices[ind] + dp[ind + 1][trans + 1],  
                        dp[ind + 1][trans]                      
                    );
                } else {
                    dp[ind][trans] = max(
                        prices[ind] + dp[ind + 1][trans + 1],   
                        dp[ind + 1][trans]                      
                    );
                }
            }
        }

        return dp[0][0]; // Start from day 0, 0th transaction
    }
};

//2nd Approach Space Optimisation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(5, 0), curr(5, 0);

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int trans = 3; trans >= 0; trans--) {
                if (trans % 2 == 0) {
                    curr[trans] = max(
                        -prices[ind] + prev[trans + 1],  
                        prev[trans]                      
                    );
                } else {
                    curr[trans] = max(
                        prices[ind] + prev[trans + 1],   
                        prev[trans]                      
                    );
                }
            }
            prev = curr; 
        }

        return prev[0];
    }
};

