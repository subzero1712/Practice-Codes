//Non Recursive
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

//Recursive
class Solution {
public:

    int solve(string &s, int i, long long num, int sign) {

        if (i >= s.size() || !isdigit(s[i]))
            return num * sign;

        num = num * 10 + (s[i] - '0');

        if (num * sign > INT_MAX)
            return INT_MAX;

        if (num * sign < INT_MIN)
            return INT_MIN;

        return solve(s, i + 1, num, sign);
    }

    int myAtoi(string s) {

        int i = 0;
        int sign = 1;
        int n = s.size();

        while (i < n && s[i] == ' ')
            i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        return solve(s, i, 0, sign);
    }
};
