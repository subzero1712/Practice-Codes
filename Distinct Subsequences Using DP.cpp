//Memoization
class Solution {
    public:
    int func(int ind1, int ind2, string s, string t, vector<vector<int>>& dp){
        if(ind2<0) return 1;
        if(ind1<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s[ind1]==t[ind2]){
            return dp[ind1][ind2]=func(ind1-1,ind2-1,s,t,dp)+func(ind1-1,ind2,s,t,dp);
        }
        else{
            return dp[ind1][ind2]=func(ind1-1,ind2,s,t,dp);
        }
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return func(s.size()-1, t.size()-1, s, t, dp);
    }
};

//Tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        const int MOD = 1e9 + 7;  

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;  
        }

        for (int j = 1; j <= m; j++) {
            dp[0][j] = 0;  
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = (dp[i - 1][j - 1] % MOD + dp[i - 1][j] % MOD) % MOD;
                } else {
                    dp[i][j] = dp[i - 1][j] % MOD;
                }
            }
        }

        return dp[n][m];
    }
};

//Space Optimisation
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        const int MOD = 1e9 + 7;  

        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);

        //1-D Space Optimization mn har row ke liye prev aur curr j==0 hone par 1 kar denge
        prev[0]=curr[0]=1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = (prev[j - 1] % MOD + prev[j] % MOD) % MOD;
                } else {
                    curr[j] = prev[j] % MOD;
                }
            }
            prev=curr;
        }

        return prev[m];
    }
};

//1-D Space Optimisation
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        const int MOD = 1e9 + 7;  

        vector<int> prev(m+1,0);

        prev[0]=1;

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    prev[j] = (prev[j - 1] % MOD + prev[j] % MOD) % MOD;
                } else {
                    prev[j] = prev[j] % MOD;
                }
            }
        }
        return prev[m];
    }
};

