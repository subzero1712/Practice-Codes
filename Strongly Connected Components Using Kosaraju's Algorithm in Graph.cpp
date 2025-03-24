#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }

    void dfs2(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs2(it, adj, vis);
            }
        }
    }

    int kosaraju(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }
        vector<vector<int>> adjT(n);
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                adjT[it].push_back(i);  
            }
        }

        fill(vis.begin(), vis.end(), 0); 
        int scc = 0;

        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc++;
                dfs2(node, adjT, vis);
            }
        }

        return scc;
    }
};
