#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t) {
    vector<vector<int>> adj(n); // Correct adjacency list declaration

    for (auto it : edges) {
        int u = it.first, v = it.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n, INT_MAX);
    dist[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int v : adj[node]) { // Corrected adjacency traversal
            if (dist[node] + 1 < dist[v]) {
                dist[v] = dist[node] + 1;
                q.push(v);
            }
        }
    }

    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        if (dist[i] != INT_MAX) {
            ans[i] = dist[i];
        }
    }

    return ans;
}
