//Brute Approach
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int zeroes=0;
            for(int j=i;j<n;j++){
                if(nums[j]==0){
                    zeroes++;
                }
                if(zeroes<=k){
                    int len=j-i+1;
                    maxlen=max(maxlen,len);
                }
                else{
                    break;
                }
            }
        }
        return maxlen;
    }
};

//Better Approach
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0;
        int l = 0;
        int r = 0;
        int zeroes = 0;

        while (r < nums.size()) {
            if (nums[r] == 0) zeroes++;

            while (zeroes > k) {
                if (nums[l] == 0) zeroes--;
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }

        return maxlen;
    }
};


//Optimal Approach
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0;
        int l = 0;
        int r = 0;
        int zeroes = 0;

        while (r < nums.size()) {
            if (nums[r] == 0) zeroes++;

            if (zeroes > k) {
                if (nums[l] == 0) zeroes--;
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }

        return maxlen;
    }
};
