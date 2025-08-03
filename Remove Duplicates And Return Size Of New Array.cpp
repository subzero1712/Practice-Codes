//1st Way
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 1;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i - 1]){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};

//2nd Way
int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int i=0;
	for(int j=1;j<n;j++){
		if(arr[i]!=arr[j]){
			arr[i+1]=arr[j];
			i++;
		}
	}
	return i+1;
}
