//Memoization
#include <bits/stdc++.h> 
int func(int ind,vector<int> weight, vector<int> value, int maxWeight,
vector<vector<int>>& dp){
	if(ind==0){
		if(weight[0]<=maxWeight) return value[0];
		else return 0;
	}
	if(dp[ind][maxWeight]!=-1) return dp[ind][maxWeight];
	int not_take=0+func(ind-1,weight,value,maxWeight,dp);
	int take=INT_MIN;
	if(weight[ind]<=maxWeight) take=value[ind]+func(ind-1,weight,value,maxWeight-weight[ind],dp);
	return dp[ind][maxWeight]=max(take,not_take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return func(n-1,weight,value,maxWeight,dp);
}

//Tabulation
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for (int w = weight[0]; w <= maxWeight; w++) {
        dp[0][w] = value[0];  
    }
    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            int not_take = dp[i - 1][w];
            int take = 0;
            if (weight[i] <= w) {
                take = value[i] + dp[i - 1][w - weight[i]];
            }
            dp[i][w] = max(take, not_take);
        }
    }

    return dp[n - 1][maxWeight];
}

//Space Optimisation
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<int> prev(maxWeight+1,0);
    vector<int> curr(maxWeight+1,0);
    for (int w = weight[0]; w <= maxWeight; w++) {
        prev[w] = value[0];  
    }
    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            int not_take = prev[w];
            int take = 0;
            if (weight[i] <= w) {
                take = value[i] + prev[w - weight[i]];
            }
            curr[w] = max(take, not_take);
        }
        prev=curr;
    }

    return prev[maxWeight];
}

//one Row Space Optimisation
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<int> prev(maxWeight+1,0);
    for (int w = weight[0]; w <= maxWeight; w++) {
        prev[w] = value[0];  
    }
    for (int i = 1; i < n; i++) {
        for (int w = maxWeight; w >=0; w--) {
            int not_take = prev[w];
            int take = 0;
            if (weight[i] <= w) {
                take = value[i] + prev[w - weight[i]];
            }
            prev[w] = max(take, not_take);
        }
    }

    return prev[maxWeight];
}
