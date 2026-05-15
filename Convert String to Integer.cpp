class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0) return 0;
        int i=0;
        int sign=1;
        long long num=0;
        int n=s.length();
        while(i<n && s[i]==' ') {
            i++;
        }
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+'){
            sign=1;
            i++;
        }
        while(i<n && isdigit(s[i])){
            num=num*10+(s[i]-'0');
            if(num*sign>INT_MAX){
                return INT_MAX;
            }
            if(num*sign<INT_MIN){
                return INT_MIN;
            }
            i++;
        }
        return num*sign;
    }
};
