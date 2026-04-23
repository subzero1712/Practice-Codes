//Brute Force Approach
class Solution {
public:
    vector<int> nextSmallerElement(vector<int> &arr)
    {
        stack<int> st;
        vector<int> ans(arr.size(),-1);
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=arr.size();
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> previousSmallerElement(vector<int>& arr){
        stack<int> st;
        vector<int> ans(arr.size(),0);
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse=nextSmallerElement(heights);
        vector<int> pse=previousSmallerElement(heights);
        int maxi=-1e9;
        for(int i=0;i<heights.size();i++){
            maxi=max(maxi,(heights[i]*(nse[i]-pse[i]-1)));
        }
        return maxi;
    }
};

//Optimal Approach
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea=-1;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int element=heights[st.top()];
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxArea=max(maxArea,element*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse=heights.size();
            int element=heights[st.top()];
            st.pop();
            int pse=st.empty()?-1:st.top();
            maxArea=max(maxArea,element*(nse-pse-1));
        }
        return maxArea;
    }
};
