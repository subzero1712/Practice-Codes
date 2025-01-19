bool canPlace(vector<int> &arr, int cows, int dist){
    int cntcows=1;
    int last=arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]-last>=dist){
            cntcows++;
            last=arr[i];
        }
        if(cntcows>=cows){
        return true;
      }
    }
  return false;  
}
int aggressiveCows(vector<int> &stalls, int k)
{
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int low=1;
    //because if there are min 2 cows than max it can be is max-min
    int high=stalls[n-1]-stalls[0];
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(canPlace(stalls, k, mid)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;;
        }
    }
    return ans;
}
