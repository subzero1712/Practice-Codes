#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        pair<int, int> source = {0, 0};
        pair<int, int> destination = {n - 1, m - 1};

        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;

        if (source == destination) return 1;  

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 0;  
        q.push({1, {0, 0}});

        int delRow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int delCol[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for (int i = 0; i < 8; i++) {  // Loop over 8 directions
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                    && grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol]) {
                    
                    dist[nrow][ncol] = dis + 1;
                    
                    if (nrow == destination.first && ncol == destination.second) 
                        return dis + 1;

                    q.push({dis + 1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};
