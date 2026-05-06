class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int sub=1<<nums.size();
        for(int i=0;i<sub;i++){
            vector<int> ls;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j)){
                    ls.push_back(nums[j]);
                }
            }
            ans.push_back(ls);
        }
        return ans;
    }
};
