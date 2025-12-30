class Solution {
public:
    bool compare(string &longer, string &shorter) {
        if (longer.length() != shorter.length() + 1) return false;

        int i = 0, j = 0;
        while (i < longer.length()) {
            if (j < shorter.length() && longer[i] == shorter[j]) {
                i++; j++;
            } else {
                i++;
            }
        }
        return j == shorter.length();
    }

    //Memoization
    int ans(int ind, int prev, vector<string>& words, vector<vector<int>>& dp) {
        if (ind == words.size()) return 0;
        if (dp[ind][prev + 1] != -1)
            return dp[ind][prev + 1];
        int not_take = ans(ind + 1, prev, words, dp);
        int take = 0;
        if (prev == -1 || compare(words[ind], words[prev])) {
            take = 1 + ans(ind + 1, ind, words, dp);
        }
        return dp[ind][prev + 1] = max(take, not_take);
    }

    int longestStrChain(vector<string>& words) {
        //Tabulation
        sort(words.begin(), words.end(),
             [](string &a, string &b){
                 return a.length() < b.length();
             });

        int n = words.size();
        vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int not_take=dp[i+1][j+1];
                int take=0;
                if(j==-1 || compare(words[i], words[j])){
                    take=1+dp[i+1][i+1];
                }
                dp[i][j+1]=max(take,not_take);
            }
        }
        return dp[0][0];
        //return ans(0, -1, words, dp);

        //Space optimisation
        sort(words.begin(), words.end(),
             [](string &a, string &b){
                 return a.length() < b.length();
             });

        int n = words.size();
        vector<int> ahead(n+1,0);
        vector<int> curr(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int not_take=ahead[j+1];
                int take=0;
                if(j==-1 || compare(words[i], words[j])){
                    take=1+ahead[i+1];
                }
                curr[j+1]=max(take,not_take);
            }
            ahead=curr;
        }
        return ahead[0];
    }
};
