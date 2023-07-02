class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        for(int i=0; i<nums.size(); i++){
        //humne temp variable isiliye banaya hai kyunki agar num mn store karate to kuch values overewrite ho jati aur shi answer nahi ata...
        temp[(i+k)%nums.size()] = nums[i];
        }
        nums = temp;
        
    }
};
