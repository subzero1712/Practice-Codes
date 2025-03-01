class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> q;
        q.push({start,0});
        vector<int> dist(99999,1e9);
        dist[start]=0;
        int mod=100000;
        if(end==start) return 0;
        while(!q.empty()){
            int node=q.front().first;
            int steps=q.front().second;
            q.pop();
            for(auto it:arr){
                int nums=(it*node)%mod;
                if(steps+1<dist[nums]){
                    dist[nums]=steps+1;
                    if(nums==end) return steps+1;
                    q.push({nums,steps+1});
                }
            }
        }
        return -1;
    }
};
