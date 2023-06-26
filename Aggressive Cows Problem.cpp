bool possibleSol(vector<int> &stalls, int k, int mid){
    int cowCount=1;
    int lastPosn=stalls[0];

    for(int i=0; i<stalls.size(); i++){
        if(stalls[i]-lastPosn>=mid){
            cowCount++;
            
            lastPosn=stalls[i];
            if(cowCount==k){
                return true;
            }
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    
    int s=0;
    int maxi=-1;
    for(int i=0; i<stalls.size(); i++){
        maxi=max(maxi,stalls[i]);
    }
    int e=maxi;
    int ans= -1;
    int mid= s + (e-s)/2;

    while(s<=e){
        if(possibleSol(stalls, k, mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
