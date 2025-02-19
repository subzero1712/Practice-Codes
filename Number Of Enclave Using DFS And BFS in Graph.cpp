//using DFS
class Solution {
    private:
    void dfs(int row, int col, vector<vector<int>> &vis,
     vector<vector<int>> &board, int delrow[], int delcol[]){
        vis[row][col]=1;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]==1){
                dfs(nrow,ncol,vis,board,delrow,delcol);
            }
        }
     }
public:
    int numEnclaves(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]==1){
                dfs(0,j,vis,board,delrow,delcol);
            }
            if(!vis[n-1][j] && board[n-1][j]==1){
                dfs(n-1,j,vis,board,delrow,delcol);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]==1){
                dfs(i,0,vis,board,delrow,delcol);
            }

            if(!vis[i][m-1] && board[i][m-1]==1){
                dfs(i,m-1,vis,board,delrow,delcol);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//using BFS
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||i==n-1||j==0||j==m-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
