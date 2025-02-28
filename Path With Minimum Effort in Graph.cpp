class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
        
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == n - 1 && c == m - 1) return dis;

            for (int i = 0; i < 4; i++) {
                int newr = r + delrow[i];
                int newc = c + delcol[i];

                if (newr >= 0 && newr < n && newc >= 0 && newc < m) {
                    int effort = max(dis, abs(heights[r][c] - heights[newr][newc]));
                    if (effort < dist[newr][newc]) {
                        dist[newr][newc] = effort;
                        pq.push({effort, {newr, newc}});
                    }
                }
            }
        }
        return 0;
    }
};
