//Memoization
#include <bits/stdc++.h> 
int func(int i, int j, vector<int> &arr, vector<vector<int>>& dp){
    if(i == j) return 0;
    int mini = 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int k = i; k < j; k++){
        int steps = arr[i-1] * arr[k] * arr[j] + 
                    func(i, k, arr, dp) + 
                    func(k+1, j, arr, dp);
        mini = min(mini, steps);
    }
    return dp[i][j]=mini;
}

int matrixMultiplication(vector<int> &arr, int N) {
    vector<vector<int>> dp(N+1, vector<int>(N+1,-1));
    return func(1, N-1, arr, dp);
}

//Tabulation
#include <bits/stdc++.h> 
int matrixMultiplication(vector<int> &arr, int N) {
    vector<vector<int>> dp(N+1, vector<int>(N+1,0));
    for(int i=1;i<N;i++){
        dp[i][i]=0;
    }
//Jab i=N-1 hoga then j=N hoga to ye condition satisfy nahi hoga aur ye skip ho jayega!
    for(int i=N-1;i>=1;i--){
        for(int j=i+1;j<N;j++){
            int mini=1e9;
            for(int k=i;k<j;k++){
                int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                mini=min(mini,steps);
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][N-1];
}
