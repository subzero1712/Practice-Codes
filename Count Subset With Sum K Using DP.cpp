//Memoization
const int mod = 1e9 + 7;

int func(int ind, int k, vector<int>& arr, vector<vector<int>>& dp) {
    if (ind == 0) {
        if (k == 0 && arr[0] == 0) return 2;
        if (k == 0 || arr[0] == k) return 1;
        return 0;
    }
    if (dp[ind][k] != -1) return dp[ind][k];
    int not_pick = func(ind - 1, k, arr, dp);
    int pick = 0;
    if (arr[ind] <= k) pick = func(ind - 1, k - arr[ind], arr, dp);
    return dp[ind][k] = (pick + not_pick) % mod;
}

int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return func(n - 1, k, arr, dp);
}

//Tabulation
int findWays(vector<int>& arr, int k)
{
    const int mod = 1e9 + 7;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    for(int i = 0; i < n; i++) dp[i][0] = 1;

    if (arr[0] == 0) dp[0][0] = 2;
    else if (arr[0] <= k) dp[0][arr[0]] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= k; j++){
            int not_pick = dp[i - 1][j];
            int pick = 0;
            if(arr[i] <= j) pick = dp[i - 1][j - arr[i]];
            dp[i][j] = (pick + not_pick)%mod;
        }
    }
    return dp[n - 1][k];
}

//Space Optimisation
int findWays(vector<int>& arr, int k)
{
    const int mod = 1e9 + 7;
    int n = arr.size();
    vector<int> prev(k+1,0);
    vector<int> curr(k+1,0);
    prev[0]=curr[0] = 1;

    if (arr[0] == 0) prev[0] = 2;
    else if (arr[0] <= k) prev[arr[0]] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= k; j++){
            int not_pick = prev[j];
            int pick = 0;
            if(arr[i] <= j) pick = prev[j - arr[i]];
            curr[j] = (pick + not_pick)%mod;
        }
        prev=curr;
    }
    return prev[k];
}
