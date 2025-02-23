//course schedule 1
class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& prerequisites) {
        vector<int> indegree(v, 0);  
        vector<vector<int>> adj(v);  
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0], w = prerequisites[i][1]; 
            adj[w].push_back(u);  
            indegree[u]++;
        }

        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        return topo.size() == v;  
    }
};

//course schedule 2
class Solution {
public:
    vector<int> findOrder(int v, vector<vector<int>>& prerequisites) {
        vector<int> indegree(v, 0);  
        vector<vector<int>> adj(v);  
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0], w = prerequisites[i][1]; 
            adj[w].push_back(u);  
            indegree[u]++;
        }

        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        if(topo.size() == v) return topo;
        return {};  
    }
};
