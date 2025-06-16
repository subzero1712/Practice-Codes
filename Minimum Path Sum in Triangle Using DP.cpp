//Memoization
class Solution {
public:
    int func(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& triangle){
        int n = triangle.size();
        if(i == n - 1) return triangle[n - 1][j]; 
        if(dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + func(i + 1, j, dp, triangle);
        int diagonal = triangle[i][j] + func(i + 1, j + 1, dp, triangle);

        return dp[i][j] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));  // max cols = rows in triangle
        return func(0, 0, dp, triangle);
    }
};

//Tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+dp[i+1][j];
                int diagonal=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,diagonal);
            } 
        }
        return dp[0][0];
    }
};

//Space Optimisation Tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<int> next(n,0);
        for(int j=0;j<n;j++){
            next[j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int> curr(n,0);
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+next[j];
                int diagonal=triangle[i][j]+next[j+1];
                curr[j]=min(down,diagonal);
            } 
            next=curr;
        }
        return next[0];
    }
};
