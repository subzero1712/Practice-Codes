//Brute Force (Recursive) Solution
class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        if(i >= j) return true;
        if(s[i] != s[j])
            return false;
        return isPalindrome(s, i+1, j-1);
    }
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                if(isPalindrome(s,i,j))
                    count++;
            }
        }
        return count;
    }
};

//Better Approach (Memoisation) Solution
class Solution {
public:
    vector<vector<int>> dp;
    bool isPalindrome(string &s, int i, int j) {
        if(i >= j)
            return true;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] != s[j])
            return dp[i][j] = false;
        return dp[i][j] =
               isPalindrome(s,i+1,j-1);
    }
    int countSubstrings(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n,-1));
        int count = 0;
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                if(isPalindrome(s,i,j))
                    count++;
            }
        }
        return count;
    }
};

//Better Approach (Tabulation) Solution
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(
            n, vector<bool>(n,false)
        );
        int count = 0;
        for(int len=1; len<=n; len++) {
            for(int i=0; i+len-1<n; i++) {
                int j = i + len - 1;
                if(len == 1) {
                    dp[i][j] = true;
                }
                else if(len == 2) {
                    dp[i][j] =
                        (s[i] == s[j]);
                }
                else {
                    dp[i][j] =
                        (s[i] == s[j]) &&
                        dp[i+1][j-1];
                }
                if(dp[i][j])
                    count++;
            }
        }
        return count;
    }
};

//Optimal Approach
class Solution {
public:
    int expand(string &s,
               int left,
               int right)
    {
        int cnt = 0;
        while(left >= 0 &&
              right < s.size() &&
              s[left] == s[right])
        {
            cnt++;
            left--;
            right++;
        }

        return cnt;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i=0;i<n;i++) {
            count += expand(s,i,i);     // odd
            count += expand(s,i,i+1);   // even
        }
        return count;
    }
};
