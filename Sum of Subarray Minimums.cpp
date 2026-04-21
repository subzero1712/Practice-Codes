//Brute Force Approach
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int mini=arr[i];
            for(int j=i;j<n;j++){
                mini=min(mini,arr[j]);
                sum+=mini;
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

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int mod = 1e9 + 7;
        vector<int> nse1=nse(arr);
        vector<int> psee1=psee(arr);
        long long total=0;
        for(int i=0;i<n;i++){
            int left=i-psee1[i];
            int right=nse1[i]-i;
            total = (total + (right*left*1LL*arr[i])%mod) % mod;
        }
        return (int)total;
    }
};
