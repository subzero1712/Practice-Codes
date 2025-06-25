//Striver Solution
string findLCS(int n, int m,string &s1, string &s2){
	vector<vector<int>> dp(n+1, vector<int>(m+1,0));
	for(int j=0;j<=m;j++){
		dp[0][j]=0;
	}
	for(int i=0;i<=n;i++){
		dp[i][0]=0;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}	
	int len=dp[n][m];
	string ans="";
	for(int i=0;i<len;i++){
		ans+='$';
	}
	int index=len-1;
	int i=n;
	int j=m;
	while(i>0 && j>0){
		if(s1[i-1]==s2[j-1]){
			ans[index]=s1[i-1];
			i=i-1;
			j=j-1;
		}
		else if(dp[i-1][j]>dp[i][j-1]){
			i=i-1;
		}
		else{
			j=j-1;
		}
	}
	return ans;
}

//Slightly Different Code
string findLCS(int n, int m, string &s1, string &s2) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = n, j = m;
    string lcs = "";
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs += s1[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    return lcs;  
}
