//Memoization
int mod = 1e9 + 7;

int func(int i, int j, bool isTrue, string &expression, vector<vector<vector<int>>> &dp) {
    if (i > j) return 0;

    if (i == j) {
        if (isTrue) return expression[i] == 'T';
        else return expression[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    int ways = 0;

    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        char op = expression[ind];

        int lt = func(i, ind - 1, 1, expression, dp);
        int lf = func(i, ind - 1, 0, expression, dp);
        int rt = func(ind + 1, j, 1, expression, dp);
        int rf = func(ind + 1, j, 0, expression, dp);

        if (op == '&') {
            if (isTrue)
                ways = (ways + 1LL * lt * rt % mod) % mod;
            else
                ways = (ways + 1LL * lt * rf % mod + 1LL * lf * rt % mod + 1LL * lf * rf % mod) % mod;
        } else if (op == '|') {
            if (isTrue)
                ways = (ways + 1LL * lt * rt % mod + 1LL * lt * rf % mod + 1LL * lf * rt % mod) % mod;
            else
                ways = (ways + 1LL * lf * rf % mod) % mod;
        } else if (op == '^') {
            if (isTrue)
                ways = (ways + 1LL * lt * rf % mod + 1LL * lf * rt % mod) % mod;
            else
                ways = (ways + 1LL * lt * rt % mod + 1LL * lf * rf % mod) % mod;
        }
    }

    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string &expression) {
    int n = expression.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    return func(0, n - 1, 1, expression, dp);
}

//Tabulation
int mod = 1e9 + 7;

int evaluateExp(string &expression) {
    int n = expression.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

    for (int i = 0; i < n; i++) {
        if (expression[i] == 'T') {
            dp[i][i][1] = 1;
            dp[i][i][0] = 0;
        } else if (expression[i] == 'F') {
            dp[i][i][1] = 0;
            dp[i][i][0] = 1;
        }
    }

    for (int len = 3; len <= n; len += 2) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            for (int isTrue = 0; isTrue <= 1; isTrue++) {
                int ways = 0;
                for (int ind = i + 1; ind <= j - 1; ind += 2) {
                    int lt = dp[i][ind - 1][1];
                    int lf = dp[i][ind - 1][0];
                    int rt = dp[ind + 1][j][1];
                    int rf = dp[ind + 1][j][0];

                    if (expression[ind] == '&') {
                        if (isTrue)
                            ways = (ways + 1LL * lt * rt % mod) % mod;
                        else
                            ways = (ways + 1LL * lt * rf % mod + 1LL * lf * rt % mod + 1LL * lf * rf % mod) % mod;
                    } else if (expression[ind] == '|') {
                        if (isTrue)
                            ways = (ways + 1LL * lt * rt % mod + 1LL * lt * rf % mod + 1LL * lf * rt % mod) % mod;
                        else
                            ways = (ways + 1LL * lf * rf % mod) % mod;
                    } else if (expression[ind] == '^') {
                        if (isTrue)
                            ways = (ways + 1LL * lt * rf % mod + 1LL * lf * rt % mod) % mod;
                        else
                            ways = (ways + 1LL * lt * rt % mod + 1LL * lf * rf % mod) % mod;
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }

    return dp[0][n - 1][1];
}
