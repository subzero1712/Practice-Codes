class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
          sort(nums.begin(), nums.end()); // Step 1: Sort the array
        long long total = 0; // To track the sum of the window
        int left = 0, result = 0;

        for (int right = 0; right < nums.size(); ++right) {
            total += nums[right]; // Add the current element to the total

            // Check if the current window is valid
            while ((long long)nums[right] * (right - left + 1) - total > k) {
                total -= nums[left]; // Remove the leftmost element from the total
                left++; // Shrink the window
            }

            // Update the result with the size of the current valid window
            result = max(result, right - left + 1);
        }

        return result;
    }

    
};
