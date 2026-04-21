//Brute Force
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;  
        for(int i=0;i<n;i++){
            int largest=nums[i];
            int smallest=nums[i];
            for(int j=i;j<n;j++){
                largest=max(largest,nums[j]);
                smallest=min(smallest,nums[j]);
                sum+=(largest-smallest);
            }
        }
        return sum;
    }
};

//Optimal Approach
class Solution {
public:
    vector<int> nse(vector<int> &arr)
    {
        int n=arr.size();
        stack<int> st;
        vector<int> ans(arr.size(),-1);
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=n;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> psee(vector<int>& arr) {
        stack<int> st;
        vector<int> ans(arr.size(),-1);
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nse1=nse(arr);
        vector<int> psee1=psee(arr);
        long long total=0;
        for(int i=0;i<n;i++){
            int left=i-psee1[i];
            int right=nse1[i]-i;
            total += (right*left*1LL*arr[i]);
        }
        return total;
    }

    vector<int> nge(vector<int> &arr)
    {
        int n=arr.size();
        stack<int> st;
        vector<int> ans(arr.size(),-1);
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=n;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> pgee(vector<int>& arr) {
        stack<int> st;
        vector<int> ans(arr.size(),-1);
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n=arr.size();
        vector<int> nge1=nge(arr);
        vector<int> pgee1=pgee(arr);
        long long total=0;
        for(int i=0;i<n;i++){
            int left=i-pgee1[i];
            int right=nge1[i]-i;
            total += (right*left*1LL*arr[i]);
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};
