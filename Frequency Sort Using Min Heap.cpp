class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({mpp[nums[i]],nums[i]});
        }
        vector<int> ans;
        while(pq.empty()!=true){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
