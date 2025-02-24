#include <bits/stdc++.h>
using namespace std;

void toposort(int node, vector<int> &vis, vector<pair<int, int>> adj[], stack<int> &st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        int v = it.first;
        if (!vis[v]) {
            toposort(v, vis, adj, st);
        }
    }
    st.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges) {
    vector<pair<int, int>> adj[n];

    // Build adjacency list
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    // Perform topological sort
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            toposort(i, vis, adj, st);
        }
    }

    vector<int> dist(n, INT_MAX);
    dist[0] = 0;  

    // Relax edges based on topological order
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (dist[node] != INT_MAX) {  
            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                if (dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
    }

    // Replace INT_MAX with -1 for unreachable nodes
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            dist[i] = -1;
        }
    }

    return dist;
}
