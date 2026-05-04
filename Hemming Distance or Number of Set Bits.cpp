//Using Modulo
class Solution {
public:
    int hammingWeight(int n) {
        int cnt=1;
        while(n>1){
            if(n%2==1){
                cnt++;
            }
            n=n/2;
        }
        return cnt;
    }
};

//Using Bitwise And
class Solution {
public:
    int hammingWeight(int n) {
        int cnt=1;
        while(n>1){
            cnt+=n&1;
            //right shift is equivalent to n/(2^n)
            n=n>>1;
        }
        return cnt;
    }
};

//Using n&n-1 Logic
class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;
        while(n!=0){
            n=n&(n-1);
            cnt++;
        }
        return cnt;
    }
};
