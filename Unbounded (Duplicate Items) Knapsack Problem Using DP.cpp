//Memoization
class Solution {
    public:
    int func(int ind,vector<int>& val, vector<int>& wt, int capacity,
    vector<vector<int>>& dp){
        if(ind==0){
            return (capacity/wt[0])*val[0];
        }
        if(dp[ind][capacity]!=-1) return dp[ind][capacity];
        int not_take=func(ind-1, val, wt, capacity,dp);
        int take=INT_MIN;
        if(wt[ind]<=capacity) take=val[ind]+func(ind, val, wt, capacity-wt[ind],dp);
        return dp[ind][capacity]=max(take,not_take);
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=wt.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
        return func(n-1,val,wt,capacity,dp);
        
    }
};

//Tabulation
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=wt.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
        
        for(int i=0;i<=capacity;i++) dp[0][i]=(i/wt[0])*val[0];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=capacity;j++){
                int not_take=dp[i-1][j];
                int take=INT_MIN;
                if(wt[i]<=j) take=val[i]+dp[i][j-wt[i]];
                dp[i][j]=max(take,not_take);
            }
        }
        return dp[n-1][capacity];
    }
};

//Space Optimization
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=wt.size();
        vector<int> prev(capacity+1,0);
        vector<int> curr(capacity+1,0);
        for(int i=0;i<=capacity;i++) prev[i]=(i/wt[0])*val[0];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=capacity;j++){
                int not_take=prev[j];
                int take=INT_MIN;
                if(wt[i]<=j) take=val[i]+curr[j-wt[i]];
                curr[j]=max(take,not_take);
            }
            prev=curr;
        }
        return prev[capacity];
    }
};

//1-D Array Space Optimisation
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=wt.size();
        vector<int> prev(capacity+1,0);
        for(int i=0;i<=capacity;i++) prev[i]=(i/wt[0])*val[0];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=capacity;j++){
                int not_take=prev[j];
                int take=INT_MIN;
                if(wt[i]<=j) take=val[i]+prev[j-wt[i]];
                prev[j]=max(take,not_take);
            }
        }
        return prev[capacity];
    }
};
