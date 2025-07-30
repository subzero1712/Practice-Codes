//Brute Force Approach
#include<bits/stdc++.h>
int kDistinctChars(int k, string &s)
{
    int maxlen=0;
        unordered_map<int,int> mpp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mpp.clear();
            for(int j=i;j<n;j++){
                mpp[s[j]]++;
                if(mpp.size()<=k){
                    maxlen=max(maxlen,j-i+1);
                }else{
                    break;
                }
            }
        }
        return maxlen;
}

//Sliding Window Approach
#include<bits/stdc++.h>
int kDistinctChars(int k, string &s)
{
    int l=0;
    int r=0;
    int n=s.size();
    int maxlen=0;
    unordered_map<char,int> mpp;
    while(r<n){
        mpp[s[r]]++;
        if(mpp.size()>k){
            while(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
        }
        if(mpp.size()<=k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}

//Optimal Approach
#include<bits/stdc++.h>
int kDistinctChars(int k, string &s)
{
    int l=0;
    int r=0;
    int n=s.size();
    int maxlen=0;
    unordered_map<char,int> mpp;
    while(r<n){
        mpp[s[r]]++;
        if(mpp.size()>k){
            if(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
        }
        if(mpp.size()<=k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}
