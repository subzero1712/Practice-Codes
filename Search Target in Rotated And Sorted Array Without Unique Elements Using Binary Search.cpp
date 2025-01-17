class Solution {
public:
    bool search(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==k) return true;
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                high--;
                low++;
                continue;
            }
            if(nums[low]<=nums[mid]){
                if(nums[low]<=k && k<=nums[mid]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }
            else{
                if(nums[mid]<=k && k<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};
