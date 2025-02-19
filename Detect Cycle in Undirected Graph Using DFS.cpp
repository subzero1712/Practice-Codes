#include<bits/stdc++.h>
class Graph {
private:
  bool dfs(int parent, int node, vector<int> adj[],int vis[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(node,it,adj,vis)){
                return true;
            }
        }
        else if(parent!=it) return true;
    }
    return false;
  }
public:
    bool detectCycle(int v, vector<int> adj[]) {
        int vis[v]={0};
        return dfs(-1,1,adj,vis);
    }
};
