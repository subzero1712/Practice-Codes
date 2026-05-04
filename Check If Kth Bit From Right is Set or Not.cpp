//Using Left Shift Operator
bool isKthBitSet(int n, int k)
{
    if((n&(1<<k-1))!=0){
        return true;
    }
    else{
        return false;
    }
}

//Using Right Shift Operator
bool isKthBitSet(int n, int k)
{
    if((n>>k-1)&1==1){
        return true;
    }
    else return false;
}
