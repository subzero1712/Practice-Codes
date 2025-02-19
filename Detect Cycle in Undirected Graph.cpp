#include<bits/stdc++.h>
class Graph {
private:
  bool detect(int src, vector<int> adj[], int vis[]){
      vis[src]=1;
      queue<pair<int,int>> q;
      q.push({src,-1});
      while(!q.empty()){
          int child=q.front().first;
          int parent=q.front().second;
          q.pop();
          for(auto it:adj[child]){
              if(!vis[it]){
                  vis[it]=1;
                  q.push({it,child});
              }
              else if(parent!=it){
                  return true;
              }
          }
      }
      return false;
  }
public:
    bool detectCycle(int v, vector<int> adj[]) {
        int vis[v]={0};
        return detect(1,adj,vis);
        //for disconnected graph
        for(int i=1;i<=v;i++){
            if(!vis[i]){  
                if(detect(i,adj,vis)) return true;
            }
        }
      return false;
    }
};
