class Solution {
    public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1,0);
    vector<bool> curr(k+1,0);
    prev[0]=true;
    curr[0] = true;  
    if (arr[0] <= k) prev[arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int target = 1; target <= k; target++) {
            bool not_take = prev[target];
            bool take = false;
            if (target >= arr[i])
                take = prev[target - arr[i]];
            curr[target] = take || not_take;
        }
        prev=curr;
    }

    return prev[k];
}
public:
    bool canPartition(vector<int>& nums) {
        int totSum=0;
        for(int i=0;i<nums.size();i++){
            totSum+=nums[i];
        }
        int target=totSum/2;
        if(totSum%2) return false;
        return subsetSumToK(nums.size(),target,nums);
    }
};
