#include <bits/stdc++.h> 

vector<int> rearrangeArray(vector<int> &A, int m){
    multimap<int,int>mp;
    for(int i=0;i<A.size();i++){
        //automatically sorts the keys
        mp.insert({abs(A[i]-m),A[i]});
    }
    vector<int>v;
    for(auto x:mp){
        v.push_back(x.second);
    }
    return v;
} 
