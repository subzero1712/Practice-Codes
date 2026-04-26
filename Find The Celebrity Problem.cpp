//Brute Force Approach
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> Iknow(n,0);
        vector<int> KnowMe(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && i!=j){
                    KnowMe[j]++;
                    Iknow[i]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(Iknow[i]==0 && KnowMe[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};

//Optimal Approach
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n=mat.size();
        int top=0;
        int down=n-1;
        while(top<down){
            if(mat[top][down]){
                top++;
            }
            else if(mat[down][top]){
                down--;
            }
            else{
                top++;
                down--;
            }
        }
        if(top>down) return -1;
        for(int i=0;i<n;i++){
            if(i==top) continue;
            
            if(mat[top][i]==1 || mat[i][top]==0){
                return -1; 
            }
        }
        
        return top;
    }
};
