#include<bits/stdc++.h>
vector<int> findOrder(int numCourses, vector<int> adj[]) {
        int indegree[numCourses]={0};
        for(int i=0;i<numCourses;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }

        }
        return topo;
    }
string getAlienLanguage(vector<string> &dictionary, int k)
{
    int n=dictionary.size();
    vector<int> adj[k];
    for(int i=0;i<n-1;i++){
        string s1=dictionary[i];
        string s2=dictionary[i+1];
        int len=min(s1.size(),s2.size());
        for(int i=0;i<len;i++){
            if(s1[i]!=s2[i]){
                adj[s1[i]-'a'].push_back(s2[i]-'a');
                break;
            }
        }
    }
    vector<int> topo=findOrder(k,adj);
    string ans="";
    for(auto it:topo){
        ans=ans+char(it+'a');
    }
    return ans;
}
