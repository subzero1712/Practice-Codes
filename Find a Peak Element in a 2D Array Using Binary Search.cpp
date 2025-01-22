int findMax(vector<vector<int>> &matrix, int n, int m, int col){
    int maxi=-1;
    int index=-1;
    for(int i=0;i<n;i++){
        if(matrix[i][col]>maxi){
            maxi=matrix[i][col];
            index=i;
        }
    }
    return index;
}
vector<int> findPeakGrid(vector<vector<int>> &g){
    int n=g.size();
    int m=g[0].size();
    int low=0;
    int high=m-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int row=findMax(g,n,m,mid);
        int left=mid-1>=0? g[row][mid-1]:-1;
        int right=mid+1<m? g[row][mid+1]:-1;
        if(g[row][mid]>left && g[row][mid]>right){
            return {row,mid};
        }
        else if(g[row][mid]<left){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return {-1, -1};
}
