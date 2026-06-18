//Using Recursion
class Solution {
public:
    bool func(string &s, int ind, int cnt){
        if(cnt<0) return false;
        if(ind==s.length()){
            return cnt==0;
        }
        if(s[ind]=='('){
            return func(s,ind+1,cnt+1);
        }
        if(s[ind]==')'){
            return func(s,ind+1,cnt-1);
        }
        return func(s,ind+1,cnt+1)||func(s,ind+1,cnt-1)||func(s,ind+1,cnt);
    }
    bool checkValidString(string s) {
        return func(s,0,0);
    }
};

//Memoization 
class Solution {
public:
    vector<vector<int>> dp;

    bool func(string &s, int ind, int cnt) {
        if(cnt < 0) return false;

        if(ind == s.size())
            return cnt == 0;

        if(dp[ind][cnt] != -1)
            return dp[ind][cnt];

        bool ans = false;

        if(s[ind] == '(') {
            ans = func(s, ind + 1, cnt + 1);
        }
        else if(s[ind] == ')') {
            ans = func(s, ind + 1, cnt - 1);
        }
        else {
            ans = func(s, ind + 1, cnt + 1) ||
                  func(s, ind + 1, cnt - 1) ||
                  func(s, ind + 1, cnt);
        }

        return dp[ind][cnt] = ans;
    }

    bool checkValidString(string s) {
        int n = s.size();
        dp.assign(n + 1, vector<int>(n + 1, -1));
        return func(s, 0, 0);
    }
};

//Tabulation
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

        dp[n][0] = true;

        for(int i = n - 1; i >= 0; i--) {
            for(int cnt = 0; cnt <= n; cnt++) {

                if(s[i] == '(') {
                    if(cnt + 1 <= n)
                        dp[i][cnt] = dp[i + 1][cnt + 1];
                }

                else if(s[i] == ')') {
                    if(cnt > 0)
                        dp[i][cnt] = dp[i + 1][cnt - 1];
                }

                else { 
                    bool open = false, close = false, empty = false;

                    if(cnt + 1 <= n)
                        open = dp[i + 1][cnt + 1];

                    if(cnt > 0)
                        close = dp[i + 1][cnt - 1];

                    empty = dp[i + 1][cnt];

                    dp[i][cnt] = open || close || empty;
                }
            }
        }

        return dp[0][0];
    }
};

//Optimal
class Solution {
public:
    bool checkValidString(string s) {
        int min=0;
        int max=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                max++;
                min++;
            }
            if(s[i]==')'){
                max--;
                min--;
            }
            if(s[i]=='*'){
                max++;
                min--;
            } 
            if(min<0) min=0;
            if(max<0) return false;
        }
        return min==0;
    }
};
