//Frog Jump 2
class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int max_jump = 0;
        for (int i = 2; i < n; i++) {
            max_jump = max(max_jump, stones[i] - stones[i - 2]);
        }
        max_jump = max(max_jump, stones[1] - stones[0]);

        return max_jump;
    }
};

//Frog Jump With K Distances
class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, 0);
        dp[0] = 0;  // Base case: 0 energy at start
        for (int i = 1; i < n; i++) {
            int min_jump = INT_MAX;
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    int jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                    min_jump = min(min_jump, jump);
                }
            }
            dp[i] = min_jump;
        }
        return dp[n - 1];  // Minimum cost to reach last stair
    }
};
