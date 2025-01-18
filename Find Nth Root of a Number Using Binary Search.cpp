int sqrt(int mid,int n,int m){
  long long ans=1;
  for(int i=1;i<=n;i++){
    ans=ans*mid;
    if(ans>m) return 2;
  }
  if(ans==m) return 1;
  return 0;
}
int NthRoot(int n, int m) {
  int low=1;
  int high=m;
  while(low<=high){
    long long mid=low+(high-low)/2;
    if(sqrt(mid,n,m)==1){
      return mid;
    }
    else if(sqrt(mid,n,m)==0){
      low=mid+1;
    }
    else{
      high=mid-1;
    }
  }
  return -1;
}
