class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<i;j++)
            {
                int x=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=x;
            }
        }
        for(int i=0;i<m;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
        
    }
};

//OR

#include<vector>

void rotateMatrix(vector<vector<int>> &mat){
	int n=mat.size();
	//transpose of a matrix
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			swap(mat[i][j], mat[j][i]);
		}
	}
	//reversing a matrix after transposing
	for(int i=0;i<n;i++){
		reverse(mat[i].begin(),mat[i].end());
	}
}
        
