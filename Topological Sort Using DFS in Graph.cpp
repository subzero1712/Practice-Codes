#include <bits/stdc++.h> 
using namespace std;

void dfs(int node, unordered_map<int, list<int>> &adj, vector<int> &vis, stack<int> &st) {
    vis[node] = 1;
    for (auto it : adj[node]) {  
        if (!vis[it]) {
            dfs(it, adj, vis, st);  
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    vector<int> vis(v, 0);
    stack<int> st;
    unordered_map<int, list<int>> adj;  

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }
    
    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
