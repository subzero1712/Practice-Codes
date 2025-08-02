//Brute Force Approach
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            unordered_map<int,int> mpp;
            for(int j=i;j<n;j++){
                mpp[nums[j]]++;
                if(mpp.size()==k) cnt++;
                else if(mpp.size()>k) break;
            }
        }
        return cnt;
    }
};

//Sliding Window Approach
class Solution {
public:
    int func(vector<int>& nums, int k){
        int l=0;
        int r=0;
        int cnt=0;
        int n=nums.size();
        unordered_map<int,int> mpp;
        if(k<0) return 0;
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }    
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
    }
};
