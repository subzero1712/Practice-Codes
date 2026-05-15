class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int maxlen=1;
        int start=0;
        for(int i=0;i<s.length();i++){
            //for even length
            int l=i-1;
            int r=i;
            while(l>=0 && r<n && s[r]==s[l]){
                if(r-l+1>maxlen) {
                    maxlen = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
            //for odd length
            l=i-1;
            r=i+1;
            while(l>=0 && r<n && s[r]==s[l]){
                if(r-l+1>maxlen) {
                    maxlen = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
        }
        return s.substr(start,maxlen);
    }
};
