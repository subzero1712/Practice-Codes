class Solution {
    public:
    void func(int ind, int sum, vector<int> &arr, int n, vector<int> &sumSubset){
        if(ind==n){
            sumSubset.push_back(sum);
            return;
        }
        //pick the element
        func(ind+1, sum+arr[ind], arr, n, sumSubset);
        //do not pick the element
        func(ind+1, sum, arr, n, sumSubset);
    }
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int> sumSubset;
        func(0,0,arr,n,sumSubset);
        sort(sumSubset.begin(), sumSubset.end());
        return sumSubset;
    }
};
