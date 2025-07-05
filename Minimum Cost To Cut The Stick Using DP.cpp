//Memoization
class Solution {
public:
    int  func(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int ind=i;ind<=j;ind++){
            int cost=cuts[j+1]-cuts[i-1]+func(i,ind-1,cuts,dp)+
            func(ind+1,j,cuts,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size()+1, vector<int>(cuts.size()+1,-1));
        return func(1,cuts.size()-2,cuts,dp);
    }
};

//Tabulation
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size()+2, vector<int>(cuts.size()+2,0));
        
        for(int i=cuts.size()-2; i>=1; i--){
            for(int j=i; j<=cuts.size()-2; j++){                
                int mini = INT_MAX; 
                for(int ind=i; ind<=j; ind++){
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                    mini = min(mini, cost);
                }
                
                dp[i][j] = mini;
            }
        }
        
        return dp[1][cuts.size()-2];
    }
};

