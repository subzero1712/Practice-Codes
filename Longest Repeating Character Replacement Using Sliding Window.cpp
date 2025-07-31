//Brute Force Approach
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 0;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mpp;
            int maxFreq = 0;
            for (int j = i; j < n; j++) {
                mpp[s[j]]++;
                maxFreq = max(maxFreq, mpp[s[j]]);
                int changes = (j - i + 1) - maxFreq;
                if (changes <= k) {
                    maxlen = max(maxlen, j - i + 1);
                } else {
                    break;
                }
            }
        }
        return maxlen;
    }
};

//Better Approach
class Solution {
public:
    int characterReplacement(string s, int k) {
        int r=0;
        int l=0;
        int n=s.size();
        int maxlen=0;
        int hash[26]={0};
        int maxf=0;
        while(r<n){
            hash[s[r]-'A']++;
            maxf=max(maxf,hash[s[r]-'A']);
            while((r-l+1)-maxf>k){
                hash[s[l]-'A']--;
                maxf=0;
                for(int i=0;i<26;i++) maxf=max(maxf,hash[i]);
                l++;
            }
            if((r-l+1)-maxf<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};

//Sliding Window Optimal Approach
class Solution {
public:
    int characterReplacement(string s, int k) {
        int r=0;
        int l=0;
        int n=s.size();
        int maxlen=0;
        int hash[26]={0};
        int maxf=0;
        while(r<n){
            hash[s[r]-'A']++;
            maxf=max(maxf,hash[s[r]-'A']);
            if((r-l+1)-maxf>k){
                hash[s[l]-'A']--;
                l++;
            }
            if((r-l+1)-maxf<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};

//Optimal Approach
class Solution {
public:
    int characterReplacement(string s, int k) {
        int r=0;
        int l=0;
        int n=s.size();
        int maxlen=0;
        unordered_map<char,int> mpp;
        int maxf=0;
        while(r<n){
            mpp[s[r]]++;
            maxf=max(maxf,mpp[s[r]]);
            int changes=(r-l+1)-maxf;
            if(changes>k){
                mpp[s[l]]--;
                l++;
            }
            if(changes<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};
