#include <bits/stdc++.h>
int flipBits(int* arr, int n) 
{
  int count=0;
  for (int i=0;i<n;i++)
      if(arr[i]==1) {arr[i]=-1; count++;}
      else  arr[i]=1;
 int sum=0;  
 int ans=0;
  for (int i=0;i<n;i++)
  {
      sum+=arr[i];
      ans=max(ans,sum);
      if(sum<0) sum=0;
  }
  return count+ans;
}
