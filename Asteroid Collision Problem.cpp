class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(asteroids[i]>0 || st.empty()){
                st.push(asteroids[i]);
            }
            else if(!st.empty() && asteroids[i]*-1==st.top()){
                st.pop();
            }
            else{
                while(!st.empty() && st.top() < asteroids[i]*-1){ 
                    st.pop();
                }
                if(st.empty() || st.top() < 0){ 
                    st.push(asteroids[i]);
                }
                else if(st.top() == asteroids[i]*-1){
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
