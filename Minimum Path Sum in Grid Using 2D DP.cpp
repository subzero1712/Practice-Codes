//Memoization
class Solution {
public:
    int func(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if (m == 0 && n == 0) return grid[0][0];
        if (m < 0 || n < 0) return INT_MAX;
        if (dp[m][n] != -1) return dp[m][n];

        int up = INT_MAX, left = INT_MAX;

        if (m > 0) {
            int upPath = func(m - 1, n, grid, dp);
            if (upPath != INT_MAX)
                up = grid[m][n] + upPath;
        }

        if (n > 0) {
            int leftPath = func(m, n - 1, grid, dp);
            if (leftPath != INT_MAX)
                left = grid[m][n] + leftPath;
        }

        return dp[m][n] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(m - 1, n - 1, grid, dp);
    }
};

//Tabulation
class Solution {
public:
  

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else{
                    int up=grid[i][j];
                    if(i>0) up+=dp[i-1][j];
                    else{
                        up+=1e9;
                    }
                    int left=grid[i][j];
                    if(j>0) left+=dp[i][j-1];
                    else{
                        left+=1e9;
                    }
                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

//Space Optimization
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) curr[j]=grid[i][j];
                else{
                    int up=grid[i][j];
                    if(i>0) up+=prev[j];
                    else{
                        up+=1e9;
                    }
                    int left=grid[i][j];
                    if(j>0) left+=curr[j-1];
                    else{
                        left+=1e9;
                    }
                    curr[j]=min(up,left);
                }
            }
            prev=curr;
        }
        return prev[n-1];
    }
};
