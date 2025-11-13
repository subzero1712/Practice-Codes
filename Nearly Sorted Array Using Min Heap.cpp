#include <bits/stdc++.h> 
vector < int > nearlySorted(vector < int > array, int n, int k) {
    priority_queue<int,vector<int>, greater<int>> pq;
    vector<int> ans;
    for(int i=0;i<array.size();i++){
        pq.push(array[i]);
        if(pq.size()>k){
            ans.push_back(pq.top());
            pq.pop();
        }
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
