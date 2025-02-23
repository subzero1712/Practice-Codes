//Using BFS
class Solution {
    private:
    bool bfs(int node, vector<vector<int>>& adjLs, vector<int> &vis, vector<int> &pathvis, vector<int> &check) {
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;
        for (auto it : adjLs[node]) {
            if (!vis[it]) {
                check[it] = 0;
                if (bfs(it, adjLs, vis, pathvis, check) == true) return true;
            }
            else if (pathvis[it] == 1) {
                check[it] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adjLs(n);  

        adjLs = graph; 

        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        vector<int> check(n, 0);
        vector<int> safe;
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                bfs(i, adjLs, vis, pathvis, check); 
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (check[i] == 1) {
                safe.push_back(i);
            }
        }
        return safe;
    }
};
//Using Kahn's Algorithm for topological sorting
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<vector<int>> rev(v);
        vector<int> indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto it: graph[i]){
                rev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> safe;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safe.push_back(node);
            for(auto it: rev[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(safe.begin(),safe.end());
        return safe;
    }
};
