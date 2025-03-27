class Solution {
    public:
    int timer = 0;
    
    void dfs(int node, int parent, int tin[], int low[], 
             vector<int> &vis, vector<int> adj[], vector<int> &mark) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0; // To count children of root
        
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (!vis[it]) {
                dfs(it, node, tin, low, vis, adj, mark);
                low[node] = min(low[node], low[it]);
                
                // If the current node is not the root and is an articulation point
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++; // Counting children
            } else {
                low[node] = min(low[node], tin[it]); // Fix: should use tin[it] instead of low[it]
            }
        }
        
        // If the root node has more than one child, it's an articulation point
        if (parent == -1 && child > 1) {
            mark[node] = 1;
        }
    }

  public:
    vector<int> articulationPoints(int n, vector<int> adj[]) {
        vector<int> vis(n, 0);
        int tin[n], low[n];
        vector<int> mark(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, tin, low, vis, adj, mark);
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (mark[i] == 1) {
                ans.push_back(i);
            }
        }
        
        return ans.empty() ? vector<int>{-1} : ans;
    }
};
