int minSumOfAbsoluteDifferences(vector<int>& arr1, vector<int>& arr2) {
    // Step 1: Sort both arrays
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    
    // Step 2: Calculate the sum of absolute differences
    int totalDifference = 0;
    for (size_t i = 0; i < arr1.size(); ++i) {
        totalDifference += abs(arr1[i] - arr2[i]);
    }
    
    return totalDifference;
}
