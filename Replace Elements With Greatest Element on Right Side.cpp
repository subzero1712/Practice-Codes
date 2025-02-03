class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxi = -1;
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = maxi;
            maxi = max(maxi, temp);  // Update maxi to be the maximum of current and previous maxi
        }
        return arr;
    }
};
