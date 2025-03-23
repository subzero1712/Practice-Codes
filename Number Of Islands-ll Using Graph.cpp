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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        int cnt=0;
        vector<int> ans;
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt++;
            
            int delr[]={-1,0,1,0};
            int delc[]={0,1,0,-1};
            for(int ind=0;ind<4;ind++){
                int adjr=row+delr[ind];
                int adjc=col+delc[ind];
                if(adjr>=0 && adjr<n && adjc>=0 && adjc<m){
                    if(vis[adjr][adjc]==1){
                        int node=row*m+col;
                        int adjnode=adjr*m+adjc;   
                        if(ds.findUPar(node)!=ds.findUPar(adjnode)){
                            cnt--;
                            ds.unionByRank(node,adjnode);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
