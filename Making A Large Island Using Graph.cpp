#include <iostream>
#include <vector>
#include <set>
using namespace std;

class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
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

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        
        // Connect existing land pieces
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) continue;
                int delr[] = {-1, 0, 1, 0};
                int delc[] = {0, 1, 0, -1};
                for (int i = 0; i < 4; i++) {
                    int adjr = row + delr[i];
                    int adjc = col + delc[i];
                    if (adjr >= 0 && adjr < n && adjc >= 0 && adjc < n && grid[adjr][adjc] == 1) {
                        int node = row * n + col;
                        int adjnode = adjr * n + adjc;
                        ds.unionBySize(node, adjnode);
                    }
                }
            }
        }

        int mx = 0;

        // Try flipping 0s to 1 and checking the largest island possible
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                int delr[] = {-1, 0, 1, 0};
                int delc[] = {0, 1, 0, -1};
                set<int> component;
                for (int i = 0; i < 4; i++) {
                    int adjr = row + delr[i];
                    int adjc = col + delc[i];
                    if (adjr >= 0 && adjr < n && adjc >= 0 && adjc < n && grid[adjr][adjc] == 1) {
                        component.insert(ds.findUPar(adjr * n + adjc));
                    }
                }

                int sizeTot = 0;
                for (auto it : component) {
                    sizeTot += ds.size[it];
                }
                mx = max(mx, sizeTot + 1);
            }
        }
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }
        
        return mx;
    }
};
