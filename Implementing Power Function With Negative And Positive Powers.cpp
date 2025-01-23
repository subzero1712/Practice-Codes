class Solution {
public:
    double myPow(double x, int n) {
        long double ans = 1.0;
        long long nn = n; // Convert n to long long to handle INT_MIN case
        if (nn < 0) {
            x = 1 / x; // If n is negative, work with reciprocal of x
            nn = -nn; // Make nn positive
        }

        while (nn > 0) {
            if (nn % 2 == 1) { // If nn is odd, multiply the answer by x
                ans *= x;
            }
            x *= x; // Square x
            nn /= 2; // Divide nn by 2
        }

        return ans;
    }
};
