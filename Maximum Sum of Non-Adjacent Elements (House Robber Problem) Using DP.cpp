//Memoization
class Solution {
private:
int func(int ind, vector<int> &nums, vector<int> &dp){
    if(ind==0) return nums[0];
    if(ind<0) return 0;

    if(dp[ind]!=-1) return dp[ind];

    int pick=nums[ind]+func(ind-2,nums,dp);
    int notPick=0+func(ind-1,nums,dp);

    return dp[ind]=max(pick,notPick);
}
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return func(n-1,nums,dp);
    }
};

//Tabulation
class Solution {
    private:
    int func(int ind, vector<int> &nums, vector<int> &dp){
        int n=nums.size();
        dp[0]=nums[0];
        if(n>1){
            dp[1]=max(nums[0],nums[1]);
        }
        for(int i=2;i<n;i++){
            int take=nums[i]+dp[i-2];
            int notTake=dp[i-1];
            dp[i]=max(take,notTake);
        }
        return dp[ind];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return func(n-1,nums,dp);
    }
};

//Space Optimized Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int notTake=prev;
            int curri=max(take,notTake);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
};
