//First And Last Elements Are Adjacent
class Solution {
    public:
    int func(vector<int> &nums){
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int not_take=prev;
            int curri=max(take,not_take);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        vector<int> temp1;
        vector<int> temp2;
        int n=nums.size();
        //this condition is required because if array size is 1 which means 1st and n-1 index will be 0 
        //which will make temp1 as empty and max function will not work
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(func(temp1),func(temp2));
    }
};
