#include<bits/stdc++.h>
bool isOp(char c){
    return (c=='/' || c=='*' || c=='+' || c=='-');
}
string postfixToPrefix(string &s){
    stack<string> st;
    for(int i=0;i<s.length();i++){
        char c=s[i];

        if(isalnum(c)){
            string op(1,c);
            st.push(op);
        }
        else if(isOp(c)){
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            string temp=c+op2+op1;
            st.push(temp);
        }
    }
    return st.top();
}
