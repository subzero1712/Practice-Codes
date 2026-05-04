int setBits(int n){

    if((n & (n+1)) ==0){
        return n;
    }
    return n | (n + 1);
}
