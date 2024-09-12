int consecutiveOnes(vector<int>& arr){
    //Write your code here.
    int max1=0;
    int cnt=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==1){
            cnt++;
            max1=max(max1,cnt);
        }
        else{
            cnt=0;
        }
    }
    return max1;
}
