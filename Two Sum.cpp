//Better Approach
#include<map>
string read(int n, vector<int> book, int target)
{
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        int a = book[i];
        int more = target-a;
        if(mpp.find(more)!=mpp.end()){
            return "YES";
        }
        mpp[a]=i;
    }
    return "NO";
}
//Optimal Approach if indexes has to be returned
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> num_with_index;
        for (int i = 0; i < nums.size(); ++i) {
            num_with_index.push_back({nums[i], i});
        }
        
        sort(num_with_index.begin(), num_with_index.end());
        
        int left = 0;
        int right = num_with_index.size() - 1;
        
        while (left < right) {
            int sum = num_with_index[left].first + num_with_index[right].first;
            if (sum == target) {
                return {num_with_index[left].second, num_with_index[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        
        return {};
    }
};
//Optimal Approach if we only need to check
string read(int n, vector<int> book, int target)
{
   int left=0;
   int right=n-1;
   sort(book.begin(), book.end());
   while(left<right){
       int sum=book[left]+book[right];
       if(target==sum){
           return "YES";
       }
       else if(sum<target) left++;
       else right--;
   }
   return "NO";
}

