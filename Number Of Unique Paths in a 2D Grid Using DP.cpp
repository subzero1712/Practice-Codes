//Memoization
class Solution {
private:
int func(int m, int n, vector<vector<int>> &dp){
    if(m==0 && n==0) return 1;
    if(m<0 || n<0) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    int up=func(m-1,n,dp);
    int right=func(m,n-1,dp);

    return dp[m][n]=up+right;
}
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(m-1,n-1,dp);
    }
};

//Tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[0][0]=1;
                else{
                  //we caannot initialize up and left outside for loop because if the if condition does not satisfy, the variables will reatain the previous value 
                  //instead of being reinitialized back to 0 and the result will always be wrong
                    int up=0;
                    int left=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
    return dp[m-1][n-1];
    }
};

//Space Optimized Tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
      //prev kind of becomes the row and we just have to see which column of the row
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) curr[j]=1;
                else{
                    int up=0;
                    int left=0;
                    if(i>0) up=prev[j];
                    if(j>0) left=curr[j-1];
                    curr[j]=up+left;
                }
            }
            prev=curr;
        }
        return prev[n-1];
    }
};
