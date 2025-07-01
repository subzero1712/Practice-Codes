class Solution {
    public:
    static bool comp(string &st1, string &st2){
        return st1.size()<st2.size();
    }
    public:
    bool check(string &s1, string &s2){
        int first=0;
        int second=0;
        if(s1.size()!=s2.size()+1) return false;
        while(first<s1.size()){
            if(second<s2.size() && s1[first]==s2[second]){
                first++;
                second++;
            }else{
                first++;
            }
        }
        if(first==s1.size() && second==s2.size()) return true;
        return false;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        int n=words.size();
        vector<int> dp(n, 1);
        int maxi = 1, lastIndex = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[i], words[j]) && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
            }
        }
        return maxi;
    }
};
