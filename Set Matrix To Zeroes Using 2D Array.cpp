//Brute Force Approach
int m = matrix.size();
int n = matrix[0].size();
for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
        if(matrix[i][j]==0 ){
            for(int k=0;k<m;k++){
                if(matrix[k][j]!=0) matrix[k][j]='-1';
                }
    			for(int k=0;k<n;k++){
                    if(matrix[i][k]!=0) matrix[i][k]='-1';
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]=='-1'){
                matrix[i][j]=0;
            }
        }
    }

//Better Approach
#include <bits/stdc++.h> 
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	int row[n]={0};
    int col[m]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				row[i]=1;
				col[j]=1;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(row[i] || col[j]){
				matrix[i][j]=0;
			}
		}
	}
	return matrix;
}

//Optimal Approach
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int col0=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0)
                        matrix[0][j]=0;
                    else{
                        col0=0;
                    }
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }
        if(col0==0){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};
