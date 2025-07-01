class Solution {
  public:
  int lowerBound(vector<int> arr, int x) {
	int low=0;
  int high=arr.size()-1;
  int ans=arr.size();
  while(low<=high){
      int mid=(low+high)/2;
      if(arr[mid]>=x){
          ans=mid;
          high=mid-1;
      } else {
          low = mid + 1;
      }
  }
  return ans;
}
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        int cnt=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                cnt++;
            }
            else{
                int ind=lowerBound(temp,nums[i]);
                temp[ind]=nums[i];
            }
        }
        return cnt;
    }
};
