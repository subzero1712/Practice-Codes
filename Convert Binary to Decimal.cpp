#include <bits/stdc++.h>

int convert(int N,string &str)
{
    int p2=1;
    int res=0;
    for(int i=N-1;i>=0;i--){
        if(str[i]=='1'){
            res+=p2;
        }
        p2=p2*2;
    }
    return res;
}
