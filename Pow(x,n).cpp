class Solution {
public:
    double myPow(double x, int n) {
        long double ans = 1.0;
        long long nn = n;
        if (nn < 0) {
            x = 1 / x; 
            nn = -nn;
        }

        while (nn > 0) {
            if (nn % 2 == 1) {
                ans *= x;
            }
            x *= x; // Square x
            nn /= 2; // Divide nn by 2
        }

        return ans;
    }
};
