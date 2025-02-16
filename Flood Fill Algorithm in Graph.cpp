class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>> &ans,vector<vector<int>> &image,
     int newCol, int delRow[], int delCol[], int iniCol){
        ans[row][col]=newCol;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
            && image[nrow][ncol]==iniCol && ans[nrow][ncol]!=newCol){
                dfs(nrow,ncol,ans,image,newCol,delRow,delCol,iniCol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor=image[sr][sc];
        vector<vector<int>> ans=image;
        int delRow[4]={-1,0,+1,0};
        int delCol[4]={0,+1,0,-1};
        dfs(sr,sc,ans,image,color,delRow,delCol,iniColor);
        return ans;
    }
};
