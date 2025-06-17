//Memoization
class Solution{
    public:
    int func(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& matrix){
        int n=matrix.size();
        if(j<0 || j>n-1) return 1e9;
        if(i==0) return matrix[0][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int s=matrix[i][j]+func(i-1,j,dp,matrix);
        int dr=matrix[i][j]+func(i-1,j+1,dp,matrix);
        int dl=matrix[i][j]+func(i-1,j-1,dp,matrix);

        return dp[i][j]=min(s,min(dr,dl));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, func(n - 1, j, dp, matrix));
        }

        return ans;
    }
};

//Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        for(int j=0;j<n;j++) dp[0][j]=matrix[0][j];

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int s=matrix[i][j]+dp[i-1][j];
                int dl=INT_MAX;
                if(j>0) dl=matrix[i][j]+dp[i-1][j-1];
                int dr=INT_MAX;
                if(j+1<n) dr=matrix[i][j]+dp[i-1][j+1];
                dp[i][j]=min(s,min(dl,dr));
            }
        }
        int mini=dp[n-1][0];
        for(int j=0;j<n;j++){
            mini=min(mini,dp[n-1][j]);
        }
        return mini;
    }
};

//Space Optimization
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> prev(n,0);
        for(int j=0;j<n;j++) prev[j]=matrix[0][j];
        for(int i=1;i<n;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                int s=matrix[i][j]+prev[j];
                int dl=INT_MAX;
                if(j>0) dl=matrix[i][j]+prev[j-1];
                int dr=INT_MAX;
                if(j+1<n) dr=matrix[i][j]+prev[j+1];
                curr[j]=min(s,min(dl,dr));
            }
            prev=curr;
        }
        int mini=prev[0];
        for(int j=0;j<n;j++){
            mini=min(mini,prev[j]);
        }
        return mini;
    }
};
