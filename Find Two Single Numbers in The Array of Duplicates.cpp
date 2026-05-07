//Brute Force Approach Using Maps
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second==1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

//Optimal Approach Using Bitwise Operator
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr=0;
        for(int i=0;i<nums.size();i++){
            xorr=xorr^nums[i];
        }
        //unsigned int rightmost = xorr & (-(unsigned int)xorr);
        int rightmost=((xorr&(xorr-1))^xorr);
        int b1=0;
        int b2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&rightmost){
                b1=b1^nums[i];
            }else{
                b2=b2^nums[i];
            }
        }
        return {b1,b2};
    }
};
