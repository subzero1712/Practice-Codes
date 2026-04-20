//Approach 1
class Solution {
public:
    void prefixMax(vector<int>& nums, vector<int>& prefMx){
        prefMx[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefMx[i]=max(prefMx[i-1],nums[i]);
        }
    }
    void suffixMax(vector<int>& nums, vector<int>& suffMx){
        suffMx[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            suffMx[i]=max(suffMx[i+1],nums[i]);
        }
    }
    int trap(vector<int>& height) {
        vector<int> prefMx(height.size(),0);
        vector<int> suffMx(height.size(),0);
        int total=0;
        prefixMax(height,prefMx);
        suffixMax(height,suffMx);
        for(int i=0;i<height.size();i++){
            int leftMax=prefMx[i];
            int rightMax=suffMx[i];
            total+=min(leftMax,rightMax)-height[i];
        }
        return total;
    }
};

//Approach 2
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0; int r=n-1;
        int leftMax=0;
        int rightMax=0;
        int total=0;
        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]>leftMax){
                    leftMax=height[l];
                }
                else{
                    total+=leftMax-height[l];
                }
                l++;
            }
            else{
                if(height[r]>rightMax){
                    rightMax=height[r];
                }
                else{
                    total+=rightMax-height[r];
                }
                r--;
            }
        }
        return total;
    }
};
