//Min Heap
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

//Sorting
#include <bits/stdc++.h> 

vector<int> Klargest(vector<int> &a, int k, int n) {

    sort(a.begin(),a.end());

    vector<int> ans;

    for(int i=n-k;i<n;i++){

        ans.push_back(a[i]);

    }

    return ans;

}
