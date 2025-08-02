//Brute Force Approach
class Solution {
public:
    string minWindow(string s, string t) {
        int minlen = 1e9;
        int sindex = -1;
        int n = s.size();
        int m = t.size();

        for (int i = 0; i <= n - m; i++) {
            int hash[256] = {0};
            for (int j = 0; j < m; j++) hash[t[j]]++;

            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (hash[s[j]] > 0) cnt++;
                hash[s[j]]--;

                if (cnt == m) {
                    if ((j - i + 1) < minlen) {
                        minlen = j - i + 1;
                        sindex = i;
                    }
                    break; 
                }
            }
        }

        return (sindex == -1) ? "" : s.substr(sindex, minlen);
    }
};

//Sliding Window Approach
class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256]={0};
        int l=0;
        int r=0;
        int minlen=1e9;
        int sindex=-1;
        int n=s.size();
        int m=t.size();
        int cnt=0;
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        while(r<n){
            if(hash[s[r]]>0) cnt++;
            hash[s[r]]--;
            while(cnt==m){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    sindex=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        return sindex==-1? "": s.substr(sindex,minlen);
    }
};
