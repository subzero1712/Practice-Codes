#include<bits/stdc++.h>
int priority(char optr){
	if(optr=='^') return 3;
	else if(optr=='/' || optr=='*') return 2;
	else if(optr=='+' || optr=='-') return 1;
	else return -1;
}
string infixToPostfix(string exp){
	int i=0;
	stack<char> st;
	string ans;
	while(i<exp.length()){
		if((exp[i]>='A' && exp[i]<='Z') ||
		(exp[i]>='a' && exp[i]<='z') || 
		(exp[i]>='0' && exp[i]<='9')){
			ans=ans+exp[i];
		}
		else if(exp[i]=='('){
			st.push(exp[i]);
		}
		else if(exp[i]==')'){
			while(!st.empty() && st.top()!='('){
				ans=ans+st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			while(!st.empty() && priority(exp[i])<=priority(st.top())){
				ans+=st.top();
				st.pop();
			}
			st.push(exp[i]);
		}
		i++;
	}
	while(!st.empty()){
		ans=ans+st.top();
		st.pop();
	}
	return ans;
}
string infixtoprefix(string exp){
  string ans;
  reverse(exp.begin(), exp.end());
  infixtopostfix(exp);
  ans=reverse(exp.begin(), exp.end());
  return ans;
}
