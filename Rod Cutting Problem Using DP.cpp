//Memoization
int func(int ind, vector<int> &price, int n, vector<vector<int>>& dp){
	if(ind==0){
		return n*price[0];
	}
	if(dp[ind][n]!=-1) return dp[ind][n];
	int not_take=0+func(ind-1,price,n,dp);
	int take=INT_MIN;
	int rod_length=ind+1;
	if(rod_length<=n) take=price[ind]+func(ind,price,n-rod_length,dp);
	return dp[ind][n]=max(take,not_take);
}
int cutRod(vector<int> &price, int n)
{
	int len=price.size();
	vector<vector<int>> dp(len, vector<int>(n+1,-1));
	return func(len-1,price,n,dp);
}

//Tabulation
int cutRod(vector<int> &price, int n)
{
	int len=price.size();
	vector<vector<int>> dp(len, vector<int>(n+1,-1));
	for(int i=0;i<=n;i++){
		dp[0][i]=price[0]*i;
	}
	for(int i=1;i<len;i++){
		for(int j=0;j<=n;j++){
			int not_take=0+dp[i-1][j];
			int take=INT_MIN;
			int rod_length=i+1;
			if(rod_length<=j) take=price[i]+dp[i][j-rod_length];
			dp[i][j]=max(take,not_take);
		}
	}
	return dp[len-1][n];
}

//Space Optimisation
int cutRod(vector<int> &price, int n)
{
	int len=price.size();
	vector<int> prev(n+1,0);
	vector<int> curr(n+1,0);
	for(int i=0;i<=n;i++){
		prev[i]=price[0]*i;
	}
	for(int i=1;i<len;i++){
		for(int j=0;j<=n;j++){
			int not_take=0+prev[j];
			int take=INT_MIN;
			int rod_length=i+1;
			if(rod_length<=j) take=price[i]+curr[j-rod_length];
			curr[j]=max(take,not_take);
		}
		prev=curr;
	}
	return prev[n];
}

//1-D Space Optimisation
int cutRod(vector<int> &price, int n)
{
	int len=price.size();
	vector<int> prev(n+1,0);
	for(int i=0;i<=n;i++){
		prev[i]=price[0]*i;
	}
	for(int i=1;i<len;i++){
		for(int j=0;j<=n;j++){
			int not_take=0+prev[j];
			int take=INT_MIN;
			int rod_length=i+1;
			if(rod_length<=j) take=price[i]+prev[j-rod_length];
			prev[j]=max(take,not_take);
		}
	}
	return prev[n];
}
