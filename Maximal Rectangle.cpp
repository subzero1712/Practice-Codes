class Solution {
public:
    void mat(vector<vector<int>>& ma){
        int n = ma.size();
        int m = ma[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i > 0 && ma[i][j] != 0)
                    ma[i][j] = ma[i-1][j] + ma[i][j];
            }
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = heights[st.top()];
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, element * (nse - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = heights.size();
            int element = heights[st.top()];
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, element * (nse - pse - 1));
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ma(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ma[i][j] = matrix[i][j] - '0';
            }
        }

        mat(ma);

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, largestRectangleArea(ma[i]));
        }
        return ans;
    }
};
