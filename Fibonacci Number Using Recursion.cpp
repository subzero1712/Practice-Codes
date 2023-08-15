class Solution {
public:
    int fib(int n) {
        //starting from zero hence for value of n=3 is 2 and not 1
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
        int ans=fib(n-1)+fib(n-2);
        return ans;
        
    }
};
