class Solution {
public:
    bool check(vector<int>& arr) {
        int n = arr.size();
        int countBreaks = 0;
        
        // Count the number of "breaks" where the current element is greater than the next one
        for (int i = 0; i < n; i++) {
          //checking last element with first element
            if (arr[i] > arr[(i + 1) % n]) {
              //counting breaks
                countBreaks++;
            }
        }
        
        // The array is sorted and rotated if there's at most one "break"
        return countBreaks <= 1;
    }
};
