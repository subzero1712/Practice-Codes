class Solution {
public:
bool possible(vector<int> &arr, int days, int k,int m){
	int cnt=0;
	int nbouquets=0;
	for(int i=0;i<arr.size();i++){
		if(arr[i]<=days){
			cnt++;
		}
		else{
			nbouquets+=(cnt/k);
			cnt=0;
		}
	}
	nbouquets+=(cnt/k);
	if(nbouquets>=m) return true;
	else{
		return false;
	}
}
int findMinElement(const std::vector<int>& arr) {
    int minElement = INT_MAX; // Start with the largest possible value
    for (int num : arr) {
        if (num < minElement) {
            minElement = num; // Update if a smaller element is found
        }
    }
    return minElement;
}
int findMaxElement(const std::vector<int>& arr) {
    int maxElement = INT_MIN; // Start with the smallest possible value
    for (int num : arr) {
        if (num > maxElement) {
            maxElement = num; // Update if a larger element is found
        }
    }
    return maxElement;
}
  int minDays(vector<int>& arr, int m, int k) {
  int low=findMinElement(arr);
	int high=findMaxElement(arr);
	int ans=-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(possible(arr, mid, k, m)){
			ans=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return ans;
    }
};
