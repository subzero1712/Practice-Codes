#include <bits/stdc++.h>

bool comp(pair<int,int>& a, pair<int,int>& b){
    return (double)a.second/a.first > (double)b.second/b.first;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(), items.end(), comp);
    double tot=0;
    for(int i=0;i<n;i++){
        if(items[i].first<=w){
            tot+=items[i].second;
            w-=items[i].first;
        }
        else{
            tot+=((double)items[i].second/items[i].first)*w;
            break;
        }
    }
    return tot;
}
