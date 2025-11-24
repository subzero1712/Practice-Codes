//Sum of Distance in MST
class Solution {
  public:
    int spanningTree(int v, vector<vector<int>> adj[]) {
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
       vector<int> vis(v,0);
       pq.push({0,0});
       int sum=0;
       while(!pq.empty()){
           auto it=pq.top();
           pq.pop();
           int node=it.second;
           int wt=it.first;
           if(vis[node]==1)continue;
           vis[node]=1;
           sum+=wt;
           for(auto it:adj[node]){
               int adjnode=it[0];
               int edw=it[1];
               if(!vis[adjnode]){
                   pq.push({edw,adjnode});
               }
           }
       }
       return sum;
    }
};

//MST Path
#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<vector<pair<int,int>>> adj(n+1);
    for(auto it : g){
        int u = it.first.first;
        int v = it.first.second;
        int w = it.second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<pair<pair<int,int>,int>> ans;
    priority_queue< pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>> > pq;
    vector<int> vis(n+1,0);
    pq.push({{0,1},-1});
    while(!pq.empty()){
        int wt=pq.top().first.first;
        int node=pq.top().first.second;
        int parent=pq.top().second;
        pq.pop();
        if(vis[node]==1) continue;
        vis[node]=1;
        if(parent!=-1){
            ans.push_back({{parent,node},wt});
        }
        for(auto &it: adj[node]){
            int adjNode=it.first;
            int adjWt=it.second;
            if(!vis[adjNode]){
                pq.push({{adjWt,adjNode},node});
            }
        }
    }
    return ans;
}
