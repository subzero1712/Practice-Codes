class Solution {
public:
    int minimum(vector<int> &nums){
        int n=nums.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<mini){
                mini=nums[i];
            }
        }
        return mini;
    }
    int maximum(vector<int> &nums){
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
        }
        return maxi;
    }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mini=nums[0];
        int maxi=nums[nums.size()-1];
        // int mini=minimum(nums);
        // int maxi=maximum(nums);
        while(mini>0 && maxi>0){
            if(maxi>mini){
                maxi=maxi%mini;
            }
            else{
                mini=mini%maxi;
            }
        }
        if(maxi==0){
            return mini;
        }
        return maxi;
    }
};
