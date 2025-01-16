int first(vector<int> &arr, int n, int k){
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==k){
            ans=mid;
            high=mid-1;
        }
        else if(arr[mid]<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int last(vector<int> &arr, int n, int k){
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==k){
            ans=mid;
            low=mid+1;
        }
        else if(arr[mid]<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    if(first(arr,n,k)==-1) return {-1,-1};
    return {first(arr,n,k),last(arr,n,k)};
}

int count(vector<int>& arr, int n, int x) {
	pair<int, int> ans=firstAndLastPosition(arr,n,x);
	if(ans.first==-1) return 0;
	return ans.second-ans.first+1;
}
