#include <bits/stdc++.h> 
vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int>ans;
    priority_queue<int,vector<int>,greater<int>>p;
    for(int i=0; i<n; ++i)
    {
        if(q[i][0]==0)
        {
            p.push(q[i][1]);
        }
        else
        {
            int value = p.top();
            ans.push_back(value);
            p.pop();
        }
    }
    return ans;
}

