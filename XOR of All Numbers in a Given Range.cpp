//Brute Force Approach
int findXOR(int L, int R){
    int xr=0;
    for(int i=L;i<=R;i++){
        xr=xr^i;
    }
    return xr;
}

//Optimal Approach Using Bitwise Operator
int XOR1toN(int n){
    if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else if(n%4==3) return 0;
    else if(n%4==0) return n;
}
int findXOR(int L, int R){
    int XORL=XOR1toN(L-1);
    int XORR=XOR1toN(R);
    return XORL^XORR;
}
