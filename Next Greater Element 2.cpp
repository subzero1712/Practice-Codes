class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size(),-1);
        for(int i=2*nums.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i%nums.size()]){
                st.pop();
            }
            if(i<nums.size()){
                if(st.empty()) ans[i]=-1;
                else ans[i]=st.top();
            }
            st.push(nums[i%nums.size()]);
        }
	return ans;
    }
};
