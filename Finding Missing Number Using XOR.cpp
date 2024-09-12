int missingNumber(vector<int>&a, int n) {
    // Write your code here.
    int xor1 = 0, xor2=0;
    int m = n-1;
    for(int i=0;i<m;i++){
        xor2=xor2^a[i];
        xor1=xor1^(i+1);
    }
    xor1=xor1^n;
    return xor1^xor2;
}
