//Memoization
class Solution {
    public:
    int func(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i>j) return 0;
        int maxi=INT_MIN;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int ind=i;ind<=j;ind++){
            int cost=nums[i-1]*nums[ind]*nums[j+1]+func(i,ind-1,nums,dp)+func(ind+1,j,nums,dp);
            maxi=max(maxi,cost);
        }
        return dp[i][j]=maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1,-1));
        return func(1,nums.size()-2,nums,dp);
    }
};

//Tabulation
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(nums.size()+2, vector<int>(nums.size()+2,0));
        for(int i=nums.size()-2;i>=1;i--){
            for(int j=i;j<=nums.size()-2;j++){
                int maxi=INT_MIN;
                for(int ind=i;ind<=j;ind++){
                    int cost=nums[i-1]*nums[ind]*nums[j+1]+dp[i][ind-1]+dp[ind+1][j];
                    maxi=max(maxi,cost);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][nums.size()-2];
    }
};
