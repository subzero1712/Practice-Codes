#include <iostream>

using namespace std;

int main()
{
  int i;
  int arr[6]={1, 1, 3, 2, 4, 6};
  int ans;
  //XORing among themselves
  for(i=0;i<6;i++){
      ans=ans^arr[i];
  //XORing with i so that only the duplicate will  remain
  for(i=1;i<6;i++){
      ans=ans^i;
  }
  }
  cout<<ans<<" ";
}
