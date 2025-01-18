bool possible(vector<int> &arr,int divisor, int limits){
	int total=0;
	for(int i=0;i<arr.size();i++){
		total+=ceil((double)arr[i]/divisor);
	}
	if(total<=limits) return true;
	else return false;
}
int findMax(const vector<int>& arr) {
    int maxElement = arr[0];  
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] > maxElement) {
            maxElement = arr[i];  
        }
    }
    return maxElement;  
}
int smallestDivisor(vector<int>& arr, int limit)
{
	int low=1;
	int high=findMax(arr);
	int ans=-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(possible(arr,mid,limit)){
			ans=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}

	}
	return ans;
}
