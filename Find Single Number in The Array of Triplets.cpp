//Brute Force Approach Using Maps
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second==1){
                return it.first;
            }
        }
        return -1;
    }
};

//Better approach 1 Using Bitwise Operator
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int bit=0;bit<32;bit++){
            int cnt=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]&(1<<bit)){
                    cnt++;
                }
            }
            if(cnt%3==1){
                ans=ans|(1<<bit);
            }
        }
        return ans
    }
};

//Better Approach 2 Using Sorting
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i=i+3){
            if(nums[i]!=nums[i-1]){
                return nums[i-1];
            }
        }
        return nums[nums.size()-1];
    }
};

//Optimal Approach Using Bucket Method
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0;
        int twos=0;
        for(int i=0;i<nums.size();i++){
            ones=(ones^nums[i])&(~twos);
            twos=(twos^nums[i])&(~ones);
        }
        return ones;
    }
};
