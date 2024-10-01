class Solution {
public: 
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();             // Get the number of rows in the matrix.
        int m = matrix[0].size();          // Get the number of columns in the matrix.
        
        // These four variables define the boundaries of the spiral traversal.
        int left = 0;                      // Initial left boundary (starting at the first column).
        int right = m - 1;                 // Initial right boundary (starting at the last column).
        int top = 0;                       // Initial top boundary (starting at the first row).
        int bottom = n - 1;                // Initial bottom boundary (starting at the last row).
        
        vector<int> ans;                   // Vector to store the elements in spiral order.
        
        // Continue looping until the boundaries converge.
        while (top <= bottom && left <= right) {
            
            // Traverse from left to right along the top row.
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]); // Add each element in the top row.
            }
            top++; // Move the top boundary down after the top row has been processed.
            
            // Traverse from top to bottom along the right column.
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]); // Add each element in the right column.
            }
            right--; // Move the right boundary left after the right column has been processed.
            
            // Check if there are remaining rows to process.
            if (top <= bottom) {
                // Traverse from right to left along the bottom row.
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]); // Add each element in the bottom row.
                }
                bottom--; // Move the bottom boundary up after the bottom row has been processed.
            }
            
            // Check if there are remaining columns to process.
            if (left <= right) {
                // Traverse from bottom to top along the left column.
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]); // Add each element in the left column.
                }
                left++; // Move the left boundary right after the left column has been processed.
            }
        }
        
        return ans; // Return the vector with the spiral order traversal of the matrix.
    }
};
