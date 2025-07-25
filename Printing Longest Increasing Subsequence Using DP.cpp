vector<int> printingLongestIncreasingSubsequence(vector<int>& nums, int n) {
    vector<int> dp(n, 1), hash(n);
    int maxi = 1, lastIndex = 0;

    for (int i = 0; i < n; i++) {
        hash[i] = i; 
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] && 1 + dp[j] > dp[i]) {
                dp[i] = 1 + dp[j];
                hash[i] = j; 
            }
        }
        if (dp[i] > maxi) {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    temp.push_back(nums[lastIndex]);
    while (hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
        temp.push_back(nums[lastIndex]);
    }
    reverse(temp.begin(), temp.end());
    return temp;
}
