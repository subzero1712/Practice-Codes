#include<bits/stdc++.h>
string postfixToPrefix(string &s){
    stack<string> st;
    int i=0;
    while(i<s.length()){
        if((s[i]>='A' && s[i]<='Z')||
        (s[i]>='a' && s[i]<='z')||
        (s[i]>='0' && s[i]<='9')){
            st.push(string(1,s[i]));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string ans=s[i]+t2+t1;
            st.push(ans);
        }
        i++;
    }
    return st.top();
}
