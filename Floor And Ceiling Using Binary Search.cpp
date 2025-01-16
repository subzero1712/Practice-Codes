pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
	int low=0;
	int high=n-1;
	int floor=-1;
	int ceil=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=x){
            ceil=arr[mid];
            high=mid-1;
        } else {
            low = mid + 1;
        }
    }
	low=0;
	high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]<=x){
            floor=arr[mid];
            low=mid+1;
        } else {
            high=mid-1;
        }
    }
    return make_pair(floor,ceil);

}
