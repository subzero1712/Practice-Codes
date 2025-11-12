int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at,at+n);
    sort(dt,dt+n);

    int plat_needed=1;
    int result=1;

    int i=1;
    int j=0;
    while(i<n && j<n){
        if(at[i]<=dt[j]){
            plat_needed++;
            i++;
        }
        else if(at[i]>dt[j]){
            plat_needed--;
            j++;
        }
        if(result<plat_needed){
            result=plat_needed;
        }
    }
    return result;
}
