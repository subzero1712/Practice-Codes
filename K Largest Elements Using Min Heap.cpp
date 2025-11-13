#include <bits/stdc++.h> 
vector<int> Klargest(vector<int> &a, int k, int n) {
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> ans;
    ans.reserve(k);
    for(int i=0;i<a.size();i++){
        pq.push(a[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
