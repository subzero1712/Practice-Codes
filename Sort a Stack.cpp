#include <bits/stdc++.h> 
void sortedinsert(stack<int> &s, int x)
{
	if(s.empty() || !s.empty() && s.top()<x)
	{
		s.push(x);
		return;
	}

	int num=s.top();
	s.pop();

	sortedinsert(s,x);
	s.push(num);
}
void sortStack(stack<int> &stack)
{
	if(stack.empty())
	{
		return;
	}
	int num=stack.top();
	stack.pop();

	sortStack(stack);

	sortedinsert(stack, num);
}
