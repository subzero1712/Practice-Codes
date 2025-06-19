//Tabulation
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int totSum=0;
        for(int i=0;i<nums.size();i++){
            totSum+=nums[i];
        }
        int target=totSum/2;
        vector<vector<bool>> dp(nums.size(),vector<bool>(target+1,false));
        for(int i=0;i<nums.size();i++) dp[i][0]=true;
        if(nums[0]<=target) dp[0][nums[0]]=true;

        for(int i=1;i<nums.size();i++){
            for(int j=1;j<target+1;j++){
                bool not_take=dp[i-1][j];
                bool take=false;
                if(j>=nums[i]) take=dp[i-1][j-nums[i]];
                dp[i][j]=(take || not_take);
            }
        }
        int minDiff=INT_MAX;
        for(int i=0;i<=target;i++){
            if(dp[nums.size()-1][i]){
                int sum1=i;
                int sum2=totSum-i;
                minDiff=min(minDiff, abs(sum1-sum2));
            }
        }
        return minDiff;
    }
};

//Space Optimization
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int totSum=0;
        for(int i=0;i<nums.size();i++){
            totSum+=nums[i];
        }
        int target=totSum/2;
        vector<int> prev(target+1,0);
        vector<int> curr(target+1,0);
        vector<vector<bool>> dp(nums.size(),vector<bool>(target+1,false));
        prev[0]=curr[0]=true;
        prev[nums[0]]=true;

        for(int i=1;i<nums.size();i++){
            for(int j=1;j<target+1;j++){
                bool not_take=prev[j];
                bool take=false;
                if(j>=nums[i]) take=prev[j-nums[i]];
                dp[i][j]=(take || not_take);
            }
            prev=curr;
        }
        int minDiff=INT_MAX;
        for(int i=0;i<=target;i++){
            if(prev[i]){
                int sum1=i;
                int sum2=totSum-i;
                minDiff=min(minDiff, abs(sum1-sum2));
            }
        }
        return minDiff;
    }
};
