class Solution {
public:
    bool canCross(vector<int>& stones) {
        const int n = stones.size();
        bool dp[2001][2002] = {};
        dp[0][1] = true;
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                int diff = stones[i] - stones[j];
                if(diff > n || !dp[j][diff]) continue;
                if(i == n - 1) return true;
                dp[i][diff] = true;
                dp[i][diff - 1] = true;
                dp[i][diff + 1] = true;
            }
        }
        return false;
    }
};
