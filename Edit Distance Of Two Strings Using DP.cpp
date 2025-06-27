//Memoization
class Solution {
public:
int func(int ind1, int ind2, string s1, string s2, vector<vector<int>>& dp){
    if(ind1<0) return ind2+1;
    if(ind2<0) return ind1+1;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    if(s1[ind1]==s2[ind2]){
        return dp[ind1][ind2]=0+func(ind1-1,ind2-1,s1,s2,dp);
    }
    int insert=1+func(ind1,ind2-1,s1,s2,dp);
    int deletion=1+func(ind1-1,ind2,s1,s2,dp);
    int replace=1+func(ind1-1,ind2-1,s1,s2,dp);
    return dp[ind1][ind2]=min(insert,min(deletion,replace));
}
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return func(word1.size()-1, word2.size()-1, word1, word2, dp);
    }
};

//Tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int j = 0; j <= m; j++) dp[0][j] = j;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=0+dp[i-1][j-1];
                }else{
                    int insert=1+dp[i][j-1];
                    int deletion=1+dp[i-1][j];
                    int replace=1+dp[i-1][j-1];
                    dp[i][j]=min(insert,min(deletion,replace));
                }
            }
        }
        return dp[n][m];
    }
};

//Space Optimisation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        for(int j = 0; j <= m; j++) prev[j] = j;

        for(int i=1;i<=n;i++){
          //agar hum upar for loop lagake ek sath set krne ka try krenge to ek hi row ke liye set hooga 
          //to vo har row ke liye set ho iske liye hum curr ko yhn likh rhe h
            curr[0] = i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j]=0+prev[j-1];
                }else{
                    int insert=1+curr[j-1];
                    int deletion=1+prev[j];
                    int replace=1+prev[j-1];
                    curr[j]=min(insert,min(deletion,replace));
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};
