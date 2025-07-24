//Brute Force Solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int hash[256]={0};
            for(int j=i;j<n;j++){
                if(hash[s[j]]==1) break;
                else{
                    int len=j-i+1;
                    maxlen=max(maxlen,len);
                    hash[s[j]]=1;
                }
            }
        }
        return maxlen;
    }
};

//Optimal Solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        fill(hash, hash + 256, -1);
        int n=s.size();
        int l=0;
        int r=0;
        int maxlen=0;
        while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            int len=r-l+1;
            maxlen=max(maxlen,len);
            hash[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};
