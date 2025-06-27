//Memoization
class Solution {
public:
    bool func(int i, int j, string p, string s, vector<vector<int>>& dp){
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return false;
        if(j < 0){
            for(int k = 0; k <= i; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(p[i] == s[j] || p[i] == '?'){
            return dp[i][j]=func(i - 1, j - 1, p, s, dp);
        }

        if(p[i] == '*'){
            return dp[i][j]=func(i - 1, j, p, s, dp) || func(i, j - 1, p, s, dp);
        }

        return dp[i][j]=false;
    }

    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return func(p.size() - 1, s.size() - 1, p, s, dp);
    }
};

//Tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        dp[0][0] = true;
        for(int j = 1; j <= n; j++) {
            dp[0][j] = false;
        }
        for(int i = 1; i <= m; i++) {
            bool flag = true;
            for(int k = 0; k < i; k++) {
                if(p[k] != '*') flag = false;
            }
            dp[i][0] = flag;
        }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(p[i-1] == s[j-1] || p[i-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[m][n];
    }
};

//Space Optimization
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<bool> prev(n+1, false), curr(n+1, false);
        prev[0] = true;

        for(int i = 1; i <= m; i++) {
            bool flag = true;
            for(int k = 0; k < i; k++) {
                if(p[k] != '*') {
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;

            for(int j = 1; j <= n; j++) {
                if(p[i-1] == s[j-1] || p[i-1] == '?') {
                    curr[j] = prev[j-1];
                }
                else if(p[i-1] == '*') {
                    curr[j] = prev[j] || curr[j-1];
                }
                else {
                    curr[j] = false;
                }
            }

            prev = curr;
        }

        return prev[n];
    }
};
