class Solution {
  public:
    int numOfPerfectSquares(int a, int b) {
        // code here
        return(floor(sqrt(b))-ceil(sqrt(a))+1);
    }
};
