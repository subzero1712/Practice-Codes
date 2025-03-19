//using dfs traversal
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

//using kruskal's algorithm
class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        DisjointSet ds(v);
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1){
                    ds.unionByRank(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<v;i++){
            if(ds.findUPar(i)==i){
                cnt++;
            }
        }
        return cnt;
    }
};
