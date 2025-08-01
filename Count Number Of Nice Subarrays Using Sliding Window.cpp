//Nice Subarrays are where count of odd numbers are equal to goal
class Solution {
public:
    int func(vector<int>& nums, int k){
        int l=0;
        int r=0;
        int n=nums.size();
        int cnt=0;
        int sum=0;
        if(k<0) return 0;
        while(r<n){
            sum+=nums[r];
            while(sum>k){
                sum-=nums[l];
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                nums[i]=1;
            }else{
                nums[i]=0;
            }
        }
        return func(nums,k)-func(nums,k-1);
    }
};
