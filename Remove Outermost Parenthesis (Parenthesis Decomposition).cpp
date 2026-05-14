//Better Approach
class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                if(!st.empty()){
                    ans+=s[i];
                }
                st.push(s[i]);
            }
            else if(s[i]==')'){
                st.pop();
                if(!st.empty()){
                    ans+=s[i];
                }
            }
        }
        return ans;
    }
};

//Optimal Approach
class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                if(cnt!=0) ans+=s[i];
                cnt++;
            }else if(s[i]==')'){
                cnt--;
                if(cnt!=0) ans+=s[i];
            }
        }
        return ans;
    }
};

//Other Way of Writing Optimal Approach
class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]==')') cnt--;
            if(cnt!=0) ans+=s[i];
            if(s[i]=='(') cnt++;
        }
        return ans;
    }
};
