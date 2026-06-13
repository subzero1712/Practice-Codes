//Recursive Solution
class Solution {
public:
    int solve(vector<int>& nums, int ind) {
        if (ind >= nums.size() - 1)
            return 0;
        int mini = 1e9;
        for (int jump = 1; jump <= nums[ind]; jump++) {
            mini = min(mini, 1 + solve(nums, ind + jump));
        }
        return mini;
    }
    int jump(vector<int>& nums) {
        return solve(nums, 0);
    }
};

//Memoization Solution
class Solution {
public:
    int solve(vector<int>& nums, int ind, vector<int>& dp) {
        if(ind >= nums.size() - 1)
            return 0;

        if(dp[ind] != -1)
            return dp[ind];

        int mini = INT_MAX;

        for(int jump = 1; jump <= nums[ind]; jump++) {
            int ans = solve(nums, ind + jump, dp);

            if(ans != INT_MAX)
                mini = min(mini, ans + 1);
        }
        return dp[ind] = mini;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};

//Tabulation SOlution
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1e9);
        dp[n - 1] = 0;
        for (int ind = n - 2; ind >= 0; ind--) {

            for (int jump = 1; jump <= nums[ind] && ind + jump < n; jump++) {
                dp[ind] = min(dp[ind],
                              1 + dp[ind + jump]);
            }
        }
        return dp[0];
    }
};

//Optimal Solution
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int l=0;
        int r=0;
        while(r<nums.size()-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                farthest=max(farthest, i+nums[i]);
            }
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }
};
