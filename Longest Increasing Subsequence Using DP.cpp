//Memoization
class Solution {
    public:
    int func(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp){
        if(ind==nums.size()) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int not_take=func(ind+1,prev,nums,dp);
        int take=INT_MIN;
        if(prev==-1 || nums[ind]>nums[prev]){
            take=1+func(ind+1,ind,nums,dp);
        }
        return dp[ind][prev+1]=max(take,not_take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1,-1));
        return func(0,-1,nums,dp);
    }
};

//Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1,0));
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int not_take=dp[i+1][j+1];
                int take=0;
                if(j==-1 || nums[i]>nums[j]){
                    take=1+dp[i+1][i+1];
                }
                dp[i][j+1]=max(take,not_take);
            }
        }
        return dp[0][0];
    }
};

//Space Optimization
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int not_take=prev[j+1];
                int take=0;
                if(j==-1 || nums[i]>nums[j]){
                    take=1+prev[i+1];
                }
                curr[j+1]=max(take,not_take);
            }
            prev=curr;
        }
        return prev[0];
    }
};

//Optimized Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i], 1+dp[j]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};
