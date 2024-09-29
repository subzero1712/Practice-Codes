//Better Approach
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int lastSmallest=INT_MIN;
        int cnt=0;
        int longest=1;
        for(int i=0;i<n;i++){
            if(nums[i]-1==lastSmallest){
                cnt++;
                lastSmallest=nums[i];
            }
            else if(nums[i]!=lastSmallest){
                cnt=1;
                lastSmallest=nums[i];
            }
            longest=max(longest,cnt);
        }
        return longest;
    }
};

//Optimal Approach
int longestSuccessiveElements(vector<int>&a) {
   int n=a.size();
   if(n==0) return 0;
   int longest=1;
   unordered_set<int> st;
   for(int i=0;i<n;i++){
       st.insert(a[i]);
   }
   for(auto it:st){
       if(st.find(it-1)==st.end()){
           int cnt=1;
           int x=it;
           while(st.find(x+1)!=st.end()){
               x=x+1;
               cnt+=1;
           }
           longest=max(longest,cnt);
       }
   }
   return longest;
}
