//Brute Force Approach
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long sum=0;
        long long cnt=0;
        while(sum+divisor<=dividend){
            cnt++;
            sum+=divisor;
        }
        return cnt;
    }
};

//Optimal Approach Using Bitwise Operator
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = true;
        if(dividend < 0 && divisor > 0) sign = false;
        if(dividend > 0 && divisor < 0) sign = false;
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long ans = 0;
        while(n >= d){
            int cnt = 0;
            while(n >= (d << (cnt + 1))){
                cnt++;
            }
            ans += (1LL << cnt);
            n -= (d << cnt);
        }
        if(ans >= (1LL << 31) && sign == true){
            return INT_MAX;
        }
        if(ans > (1LL << 31) && sign == false){
            return INT_MIN;
        }
        return sign ? ans : (-1 * ans);
    }
};
