class Solution {
private:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int node) {
        vis[node] = 1;  
        for (auto it : adj[node]) {
            if (!vis[it]) {  
                dfs(adj, vis, it);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();  
        vector<vector<int>> adjLs(v); 

        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        vector<int> vis(v, 0); 
        int cnt = 0;

        for (int i = 0; i < v; i++) {  
            if (!vis[i]) {
                cnt++;
                dfs(adjLs, vis, i);
            }
        }

        return cnt;
    }
};
