class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            //we will not use sqrt as for bigger and near values the float values can be too 
            //near and for int type it can be same long after decimal so to avoid it use int 
            //or long long if using sqrt for e.g [9997][9997] and [9996][9998]
            int dist=(x*x)+(y*y);
            pq.push({dist,{x,y}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(pq.empty()!=true){
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            ans.push_back({x,y});
            pq.pop();
        }
        return ans;
    }
};
