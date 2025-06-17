//Memoization
class Solution {
    public:
    int func(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        int n=grid.size();
        int m=grid[0].size();
        if(j1<0 || j1>m-1 || j2<0 || j2>m-1){
            return -1e9;
        }
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            else{
                return grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=-1e9;
        for(int dj1=-1;dj1<=+1;dj1++){
            for(int dj2=-1;dj2<=+1;dj2++){
                int value=0;
                if(j1==j2) value=grid[i][j1];
                else value=grid[i][j1]+grid[i][j2];
                value+=func(i+1,j1+dj1,j2+dj2,grid,dp);
                maxi=max(maxi,value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,-1)));
        return func(0,0,m-1,grid,dp);
    }
};

//Tabulation
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,-1)));
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if(j1==j2) dp[n-1][j1][j2]=grid[n-1][j1];
                else dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    int maxi=-1e9;
                    for(int dj1=-1;dj1<=+1;dj1++){
                        for(int dj2=-1;dj2<=+1;dj2++){
                        int value=0;
                        if(j1==j2) value=grid[i][j1];
                        else value=grid[i][j1]+grid[i][j2];
                          //pehele hum function lerhe the to vo base case ki wajah se out of bound nahi hoga lekin dp array ho skti hai 
                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m){
                            value+=dp[i+1][j1+dj1][j2+dj2];
                        }else{
                            value+=-1e9;
                        }
                        
                        maxi=max(maxi,value);
                    }
                }
                dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
};

//Space Optimisation
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> prev(m, vector<int>(m, 0));

        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2)
                    prev[j1][j2] = grid[n - 1][j1];
                else
                    prev[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            vector<vector<int>> curr(m, vector<int>(m, 0));
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = -1e9;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;
                            int value;
                            if (j1 == j2)
                                value = grid[i][j1];
                            else
                                value = grid[i][j1] + grid[i][j2];

                            if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m)
                                value += prev[nj1][nj2];
                            else
                                value += -1e9;

                            maxi = max(maxi, value);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            prev = curr;
        }

        return prev[0][m - 1];
    }
};
