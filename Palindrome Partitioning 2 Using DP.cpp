//Memoization
class Solution {
public:
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    int func(int i, string& s, vector<int>& dp){
        if (i == s.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int minCost = INT_MAX;
        for (int j = i; j < s.size(); j++) {
            //we are not creating temp instead we are passing the index i and j which is same
            if (isPalindrome(s, i, j)) {
                int cost = 1 + func(j + 1, s, dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[i] = minCost;
    }

    int minCut(string s) {
        vector<int> dp(s.size(), -1);
        return func(0, s, dp) - 1; 
    }
};

//Tabulation
class Solution {
public:
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    int minCut(string s) {
        vector<int> dp(s.size()+1, 0);
        dp[s.size()]=0;
        for(int i=s.size()-1;i>=0;i--){
            int minCost = INT_MAX;
            for (int j = s.size()-1; j>=i; j--) {
                //we are not creating temp instead we are passing the index i and j which is same
                if (isPalindrome(s, i, j)) {
                    int cost = 1 + dp[j+1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
            }
        return dp[0]-1; 
    }
};
